#include "retrieveutils.h"

extern  map<string, string> g_ConfMap;

void* retrieveInterface(void *args) {
    InputInterface* inputArgs= (InputInterface*)args;
    string purl = inputArgs->imgurl, imgsaveurl = inputArgs->saveurl;
    
    int upleftx = inputArgs->upleftx, uplefty = inputArgs->uplefty, height = inputArgs->height, width = inputArgs->width;
    WordRes* pObj = new(std::nothrow) WordRes;
    pObj->status = 0;
    bool flag = false;
    time_t now;
    struct tm * timenow;
    //裁剪图像
    flag = imgcap(purl,upleftx,uplefty,height,width,imgsaveurl);
    if(flag == false){
        pObj->status = -1;
        Log::Error("ImgCap Error !");
        return (void*)pObj;
    }

    //vector<int> rres; //检测结果
    /*Recognition：geographic information*/
    vector<int> gires;
    int regflag = RegByGeoInf(imgsaveurl,*(inputArgs->p_targetgeo),gires);
    if(regflag == -1){
        pObj->status = -1;
        Log::Error("RegByGeoInf Error !");
        return (void*)pObj;
    } 
    else if(regflag == 1){ //图像包含地理信息
        if(gires.size() != 0){ //地理范围内存在已知目标
            for(vector<int>::iterator it = gires.begin(); it != gires.end(); it++){
                ImgInfo imginf;
               imginf.id = inputArgs->p_targetno[*(it)];
                imginf.name = inputArgs->p_targetname[*(it)];
                imginf.path = inputArgs->p_targetgeomark[*(it)];
                pObj->keyWords.push_back(imginf);
            }
            //rres.assign(gires.begin(), gires.end());
            pObj->status = 2; //正常-遥感图像
        }
        else{
            Log::Warn(imgsaveurl+" This target can not be recognized.");
            pObj->status = 0; //没有找到目标
        }
    }
    else{
        /*Recognition：ASIFT and Sparse Representation*/
        //ASIFT
        time(&now);
        timenow = localtime(&now);
        time_t start = mktime(timenow);
        cout << "ASIFT Start." << endl;
        string featuresaveurl = inputArgs->featureurl;
        cout << "Feature Save URL ## " << featuresaveurl << endl;
        vector<vector<float>> imgFeatures;
        flag = AsiftFeature(featuresaveurl, imgsaveurl, imgFeatures);
//      flag = AsiftFeature(featuresaveurl, purl, imgFeatures);
        if(flag == false) {
            Log::Error("Fetch RetrieveServer Result Struct Failed !");
            pObj->status = -1;
            return (void*)pObj;
        }
        time(&now);
        timenow = localtime(&now);
        time_t end = mktime(timenow);
        cout << "ASIFT Done. Running time:" << difftime(end,start) << endl;

        //Sparse Representation
        time(&now);
        timenow = localtime(&now);
        start = mktime(timenow);
        cout << "Sparse Representation Start." << endl;
        vector<int> srres; //分类类别
        vector<int> srprob;//分类类别对应的概率
        float p_min_residual = inputArgs->p_min_residual;
        int p_sparsity = inputArgs->p_sparsity;
        flag = inputArgs->p_SRClassify->SRClassify(imgFeatures, p_min_residual, p_sparsity, srres, srprob);
        if(flag == false ) { //|| srres.size() != p_targetname.size()
            Log::Error("Fetch RetrieveServer Result Struct Failed !");
            pObj->status = -1;
            return (void*)pObj;
        }
        time(&now);
        timenow = localtime(&now);
        end = mktime(timenow);
        cout << "Sparse Representation Done. Running time:" << difftime(end,start) << endl;
        
        srres.resize(srres.size()>=10 ? 10:srres.size()); //取前3个或小于3个
        int i;
        for(i = 0; i<srres.size(); i++){
            ImgInfo imginf;
            imginf.id = inputArgs->p_targetno[srres[i]];
            imginf.name = inputArgs->p_targetname[srres[i]];//+"_"+to_string(srprob[i])+"%";
            imginf.path = inputArgs->p_targetgeomark[srres[i]];
            pObj->keyWords.push_back(imginf);
        }
        
        //rres.assign(srres.begin(), srres.end());
        pObj->status = 1; //正常-普通图像
    }
    /*将遥感图和普通图分为一类，检索结果去重*/
    /***********************************************************
    int rsize = rres.size();//检索个数
    for(int i = rsize-1; i >= 1; i--){
        string targetname = inputArgs->p_targetname[i];
        for(int j = i-1; j >= 0; j--){
            if(inputArgs->p_targetname[j] == targetname){ //
                rres.erase(rres.begin()+i);
                break;//只会重复一次
            }         
        }
    }
    for(vector<int>::iterator it = rres.begin(); it != rres.end(); it++){
         ImgInfo imginf;
         imginf.id = inputArgs->p_targetno[*(it)];
         imginf.name = inputArgs->p_targetname[*(it)];
         imginf.path = inputArgs->p_targetgeomark[*(it)];
         pObj->keyWords.push_back(imginf);
    }
    ***********************************************************/
    return (void*)pObj;
}

void deepCopyWordRes(WordRes* src, WordRes& dest) {
    dest.status = src->status;
    for(vector<ImgInfo>::iterator it=src->keyWords.begin(); it != src->keyWords.end(); ++it) {
        dest.keyWords.push_back(*it);
    }
}

