// **********************************************************************
//
// Copyright (c) 2003-2016 ZeroC, Inc. All rights reserved.
//
// This copy of Ice is licensed to you under the terms described in the
// ICE_LICENSE file included in this distribution.
//
// **********************************************************************
//
// Ice version 3.6.2
//
// <auto-generated>
//
// Generated from file `ImageRetrieveRpc.ice'
//
// Warning: do not edit this file.
//
// </auto-generated>
//

#include "ImageRetrieveRpc.h"
#include <IceUtil/PushDisableWarnings.h>
#include <Ice/LocalException.h>
#include <Ice/ObjectFactory.h>
#include <Ice/Outgoing.h>
#include <Ice/OutgoingAsync.h>
#include <Ice/BasicStream.h>
#include <IceUtil/Iterator.h>
#include <IceUtil/PopDisableWarnings.h>

#ifndef ICE_IGNORE_VERSION
#   if ICE_INT_VERSION / 100 != 306
#       error Ice version mismatch!
#   endif
#   if ICE_INT_VERSION % 100 > 50
#       error Beta header file detected
#   endif
#   if ICE_INT_VERSION % 100 < 2
#       error Ice patch level mismatch!
#   endif
#endif

namespace
{

const ::std::string __RPCImgRecong__ImgRetrieval__wordGetKnowledge_name = "wordGetKnowledge";

const ::std::string __RPCImgRecong__ImgRetrieval__wordSearch_name = "wordSearch";

const ::std::string __RPCImgRecong__ImgRetrieval__wordSearchImg_name = "wordSearchImg";

const ::std::string __RPCImgRecong__ImgRetrieval__imgSearchAsync_name = "imgSearchAsync";

const ::std::string __RPCImgRecong__ImgRetrieval__fetchImgSearchResult_name = "fetchImgSearchResult";

const ::std::string __RPCImgRecong__ImgRetrieval__imgSearchSync_name = "imgSearchSync";

}

namespace Ice
{
}
::IceProxy::Ice::Object* ::IceProxy::RPCImgRecong::upCast(::IceProxy::RPCImgRecong::ImgRetrieval* p) { return p; }

void
::IceProxy::RPCImgRecong::__read(::IceInternal::BasicStream* __is, ::IceInternal::ProxyHandle< ::IceProxy::RPCImgRecong::ImgRetrieval>& v)
{
    ::Ice::ObjectPrx proxy;
    __is->read(proxy);
    if(!proxy)
    {
        v = 0;
    }
    else
    {
        v = new ::IceProxy::RPCImgRecong::ImgRetrieval;
        v->__copyFrom(proxy);
    }
}

::RPCImgRecong::WordWiki
IceProxy::RPCImgRecong::ImgRetrieval::wordGetKnowledge(const ::std::string& __p_word, const ::Ice::Context* __ctx)
{
    __checkTwowayOnly(__RPCImgRecong__ImgRetrieval__wordGetKnowledge_name);
    ::IceInternal::Outgoing __og(this, __RPCImgRecong__ImgRetrieval__wordGetKnowledge_name, ::Ice::Normal, __ctx);
    try
    {
        ::IceInternal::BasicStream* __os = __og.startWriteParams(::Ice::DefaultFormat);
        __os->write(__p_word);
        __og.endWriteParams();
    }
    catch(const ::Ice::LocalException& __ex)
    {
        __og.abort(__ex);
    }
    if(!__og.invoke())
    {
        try
        {
            __og.throwUserException();
        }
        catch(const ::Ice::UserException& __ex)
        {
            ::Ice::UnknownUserException __uue(__FILE__, __LINE__, __ex.ice_name());
            throw __uue;
        }
    }
    ::RPCImgRecong::WordWiki __ret;
    ::IceInternal::BasicStream* __is = __og.startReadParams();
    __is->read(__ret);
    __og.endReadParams();
    return __ret;
}

::Ice::AsyncResultPtr
IceProxy::RPCImgRecong::ImgRetrieval::begin_wordGetKnowledge(const ::std::string& __p_word, const ::Ice::Context* __ctx, const ::IceInternal::CallbackBasePtr& __del, const ::Ice::LocalObjectPtr& __cookie)
{
    __checkAsyncTwowayOnly(__RPCImgRecong__ImgRetrieval__wordGetKnowledge_name);
    ::IceInternal::OutgoingAsyncPtr __result = new ::IceInternal::OutgoingAsync(this, __RPCImgRecong__ImgRetrieval__wordGetKnowledge_name, __del, __cookie);
    try
    {
        __result->prepare(__RPCImgRecong__ImgRetrieval__wordGetKnowledge_name, ::Ice::Normal, __ctx);
        ::IceInternal::BasicStream* __os = __result->startWriteParams(::Ice::DefaultFormat);
        __os->write(__p_word);
        __result->endWriteParams();
        __result->invoke();
    }
    catch(const ::Ice::Exception& __ex)
    {
        __result->abort(__ex);
    }
    return __result;
}

#ifdef ICE_CPP11

::Ice::AsyncResultPtr
IceProxy::RPCImgRecong::ImgRetrieval::__begin_wordGetKnowledge(const ::std::string& __p_word, const ::Ice::Context* __ctx, const ::IceInternal::Function<void (const ::RPCImgRecong::WordWiki&)>& __response, const ::IceInternal::Function<void (const ::Ice::Exception&)>& __exception, const ::IceInternal::Function<void (bool)>& __sent)
{
    class Cpp11CB : public ::IceInternal::Cpp11FnCallbackNC
    {
    public:

        Cpp11CB(const ::std::function<void (const ::RPCImgRecong::WordWiki&)>& responseFunc, const ::std::function<void (const ::Ice::Exception&)>& exceptionFunc, const ::std::function<void (bool)>& sentFunc) :
            ::IceInternal::Cpp11FnCallbackNC(exceptionFunc, sentFunc),
            _response(responseFunc)
        {
            CallbackBase::checkCallback(true, responseFunc || exceptionFunc != nullptr);
        }

        virtual void completed(const ::Ice::AsyncResultPtr& __result) const
        {
            ::RPCImgRecong::ImgRetrievalPrx __proxy = ::RPCImgRecong::ImgRetrievalPrx::uncheckedCast(__result->getProxy());
            ::RPCImgRecong::WordWiki __ret;
            try
            {
                __ret = __proxy->end_wordGetKnowledge(__result);
            }
            catch(const ::Ice::Exception& ex)
            {
                Cpp11FnCallbackNC::exception(__result, ex);
                return;
            }
            if(_response != nullptr)
            {
                _response(__ret);
            }
        }
    
    private:
        
        ::std::function<void (const ::RPCImgRecong::WordWiki&)> _response;
    };
    return begin_wordGetKnowledge(__p_word, __ctx, new Cpp11CB(__response, __exception, __sent));
}
#endif

::RPCImgRecong::WordWiki
IceProxy::RPCImgRecong::ImgRetrieval::end_wordGetKnowledge(const ::Ice::AsyncResultPtr& __result)
{
    ::Ice::AsyncResult::__check(__result, this, __RPCImgRecong__ImgRetrieval__wordGetKnowledge_name);
    ::RPCImgRecong::WordWiki __ret;
    if(!__result->__wait())
    {
        try
        {
            __result->__throwUserException();
        }
        catch(const ::Ice::UserException& __ex)
        {
            throw ::Ice::UnknownUserException(__FILE__, __LINE__, __ex.ice_name());
        }
    }
    ::IceInternal::BasicStream* __is = __result->__startReadParams();
    __is->read(__ret);
    __result->__endReadParams();
    return __ret;
}

::RPCImgRecong::WordRes
IceProxy::RPCImgRecong::ImgRetrieval::wordSearch(const ::RPCImgRecong::DictStr2Str& __p_mapArg, const ::Ice::Context* __ctx)
{
    __checkTwowayOnly(__RPCImgRecong__ImgRetrieval__wordSearch_name);
    ::IceInternal::Outgoing __og(this, __RPCImgRecong__ImgRetrieval__wordSearch_name, ::Ice::Normal, __ctx);
    try
    {
        ::IceInternal::BasicStream* __os = __og.startWriteParams(::Ice::DefaultFormat);
        __os->write(__p_mapArg);
        __og.endWriteParams();
    }
    catch(const ::Ice::LocalException& __ex)
    {
        __og.abort(__ex);
    }
    if(!__og.invoke())
    {
        try
        {
            __og.throwUserException();
        }
        catch(const ::Ice::UserException& __ex)
        {
            ::Ice::UnknownUserException __uue(__FILE__, __LINE__, __ex.ice_name());
            throw __uue;
        }
    }
    ::RPCImgRecong::WordRes __ret;
    ::IceInternal::BasicStream* __is = __og.startReadParams();
    __is->read(__ret);
    __og.endReadParams();
    return __ret;
}

::Ice::AsyncResultPtr
IceProxy::RPCImgRecong::ImgRetrieval::begin_wordSearch(const ::RPCImgRecong::DictStr2Str& __p_mapArg, const ::Ice::Context* __ctx, const ::IceInternal::CallbackBasePtr& __del, const ::Ice::LocalObjectPtr& __cookie)
{
    __checkAsyncTwowayOnly(__RPCImgRecong__ImgRetrieval__wordSearch_name);
    ::IceInternal::OutgoingAsyncPtr __result = new ::IceInternal::OutgoingAsync(this, __RPCImgRecong__ImgRetrieval__wordSearch_name, __del, __cookie);
    try
    {
        __result->prepare(__RPCImgRecong__ImgRetrieval__wordSearch_name, ::Ice::Normal, __ctx);
        ::IceInternal::BasicStream* __os = __result->startWriteParams(::Ice::DefaultFormat);
        __os->write(__p_mapArg);
        __result->endWriteParams();
        __result->invoke();
    }
    catch(const ::Ice::Exception& __ex)
    {
        __result->abort(__ex);
    }
    return __result;
}

#ifdef ICE_CPP11

::Ice::AsyncResultPtr
IceProxy::RPCImgRecong::ImgRetrieval::__begin_wordSearch(const ::RPCImgRecong::DictStr2Str& __p_mapArg, const ::Ice::Context* __ctx, const ::IceInternal::Function<void (const ::RPCImgRecong::WordRes&)>& __response, const ::IceInternal::Function<void (const ::Ice::Exception&)>& __exception, const ::IceInternal::Function<void (bool)>& __sent)
{
    class Cpp11CB : public ::IceInternal::Cpp11FnCallbackNC
    {
    public:

        Cpp11CB(const ::std::function<void (const ::RPCImgRecong::WordRes&)>& responseFunc, const ::std::function<void (const ::Ice::Exception&)>& exceptionFunc, const ::std::function<void (bool)>& sentFunc) :
            ::IceInternal::Cpp11FnCallbackNC(exceptionFunc, sentFunc),
            _response(responseFunc)
        {
            CallbackBase::checkCallback(true, responseFunc || exceptionFunc != nullptr);
        }

        virtual void completed(const ::Ice::AsyncResultPtr& __result) const
        {
            ::RPCImgRecong::ImgRetrievalPrx __proxy = ::RPCImgRecong::ImgRetrievalPrx::uncheckedCast(__result->getProxy());
            ::RPCImgRecong::WordRes __ret;
            try
            {
                __ret = __proxy->end_wordSearch(__result);
            }
            catch(const ::Ice::Exception& ex)
            {
                Cpp11FnCallbackNC::exception(__result, ex);
                return;
            }
            if(_response != nullptr)
            {
                _response(__ret);
            }
        }
    
    private:
        
        ::std::function<void (const ::RPCImgRecong::WordRes&)> _response;
    };
    return begin_wordSearch(__p_mapArg, __ctx, new Cpp11CB(__response, __exception, __sent));
}
#endif

::RPCImgRecong::WordRes
IceProxy::RPCImgRecong::ImgRetrieval::end_wordSearch(const ::Ice::AsyncResultPtr& __result)
{
    ::Ice::AsyncResult::__check(__result, this, __RPCImgRecong__ImgRetrieval__wordSearch_name);
    ::RPCImgRecong::WordRes __ret;
    if(!__result->__wait())
    {
        try
        {
            __result->__throwUserException();
        }
        catch(const ::Ice::UserException& __ex)
        {
            throw ::Ice::UnknownUserException(__FILE__, __LINE__, __ex.ice_name());
        }
    }
    ::IceInternal::BasicStream* __is = __result->__startReadParams();
    __is->read(__ret);
    __result->__endReadParams();
    return __ret;
}

::RPCImgRecong::ImgRes
IceProxy::RPCImgRecong::ImgRetrieval::wordSearchImg(const ::RPCImgRecong::DictStr2Str& __p_mapArg, const ::Ice::Context* __ctx)
{
    __checkTwowayOnly(__RPCImgRecong__ImgRetrieval__wordSearchImg_name);
    ::IceInternal::Outgoing __og(this, __RPCImgRecong__ImgRetrieval__wordSearchImg_name, ::Ice::Normal, __ctx);
    try
    {
        ::IceInternal::BasicStream* __os = __og.startWriteParams(::Ice::DefaultFormat);
        __os->write(__p_mapArg);
        __og.endWriteParams();
    }
    catch(const ::Ice::LocalException& __ex)
    {
        __og.abort(__ex);
    }
    if(!__og.invoke())
    {
        try
        {
            __og.throwUserException();
        }
        catch(const ::Ice::UserException& __ex)
        {
            ::Ice::UnknownUserException __uue(__FILE__, __LINE__, __ex.ice_name());
            throw __uue;
        }
    }
    ::RPCImgRecong::ImgRes __ret;
    ::IceInternal::BasicStream* __is = __og.startReadParams();
    __is->read(__ret);
    __og.endReadParams();
    return __ret;
}

::Ice::AsyncResultPtr
IceProxy::RPCImgRecong::ImgRetrieval::begin_wordSearchImg(const ::RPCImgRecong::DictStr2Str& __p_mapArg, const ::Ice::Context* __ctx, const ::IceInternal::CallbackBasePtr& __del, const ::Ice::LocalObjectPtr& __cookie)
{
    __checkAsyncTwowayOnly(__RPCImgRecong__ImgRetrieval__wordSearchImg_name);
    ::IceInternal::OutgoingAsyncPtr __result = new ::IceInternal::OutgoingAsync(this, __RPCImgRecong__ImgRetrieval__wordSearchImg_name, __del, __cookie);
    try
    {
        __result->prepare(__RPCImgRecong__ImgRetrieval__wordSearchImg_name, ::Ice::Normal, __ctx);
        ::IceInternal::BasicStream* __os = __result->startWriteParams(::Ice::DefaultFormat);
        __os->write(__p_mapArg);
        __result->endWriteParams();
        __result->invoke();
    }
    catch(const ::Ice::Exception& __ex)
    {
        __result->abort(__ex);
    }
    return __result;
}

#ifdef ICE_CPP11

::Ice::AsyncResultPtr
IceProxy::RPCImgRecong::ImgRetrieval::__begin_wordSearchImg(const ::RPCImgRecong::DictStr2Str& __p_mapArg, const ::Ice::Context* __ctx, const ::IceInternal::Function<void (const ::RPCImgRecong::ImgRes&)>& __response, const ::IceInternal::Function<void (const ::Ice::Exception&)>& __exception, const ::IceInternal::Function<void (bool)>& __sent)
{
    class Cpp11CB : public ::IceInternal::Cpp11FnCallbackNC
    {
    public:

        Cpp11CB(const ::std::function<void (const ::RPCImgRecong::ImgRes&)>& responseFunc, const ::std::function<void (const ::Ice::Exception&)>& exceptionFunc, const ::std::function<void (bool)>& sentFunc) :
            ::IceInternal::Cpp11FnCallbackNC(exceptionFunc, sentFunc),
            _response(responseFunc)
        {
            CallbackBase::checkCallback(true, responseFunc || exceptionFunc != nullptr);
        }

        virtual void completed(const ::Ice::AsyncResultPtr& __result) const
        {
            ::RPCImgRecong::ImgRetrievalPrx __proxy = ::RPCImgRecong::ImgRetrievalPrx::uncheckedCast(__result->getProxy());
            ::RPCImgRecong::ImgRes __ret;
            try
            {
                __ret = __proxy->end_wordSearchImg(__result);
            }
            catch(const ::Ice::Exception& ex)
            {
                Cpp11FnCallbackNC::exception(__result, ex);
                return;
            }
            if(_response != nullptr)
            {
                _response(__ret);
            }
        }
    
    private:
        
        ::std::function<void (const ::RPCImgRecong::ImgRes&)> _response;
    };
    return begin_wordSearchImg(__p_mapArg, __ctx, new Cpp11CB(__response, __exception, __sent));
}
#endif

::RPCImgRecong::ImgRes
IceProxy::RPCImgRecong::ImgRetrieval::end_wordSearchImg(const ::Ice::AsyncResultPtr& __result)
{
    ::Ice::AsyncResult::__check(__result, this, __RPCImgRecong__ImgRetrieval__wordSearchImg_name);
    ::RPCImgRecong::ImgRes __ret;
    if(!__result->__wait())
    {
        try
        {
            __result->__throwUserException();
        }
        catch(const ::Ice::UserException& __ex)
        {
            throw ::Ice::UnknownUserException(__FILE__, __LINE__, __ex.ice_name());
        }
    }
    ::IceInternal::BasicStream* __is = __result->__startReadParams();
    __is->read(__ret);
    __result->__endReadParams();
    return __ret;
}

::Ice::Int
IceProxy::RPCImgRecong::ImgRetrieval::imgSearchAsync(const ::RPCImgRecong::DictStr2Str& __p_mapArg, const ::Ice::Context* __ctx)
{
    __checkTwowayOnly(__RPCImgRecong__ImgRetrieval__imgSearchAsync_name);
    ::IceInternal::Outgoing __og(this, __RPCImgRecong__ImgRetrieval__imgSearchAsync_name, ::Ice::Normal, __ctx);
    try
    {
        ::IceInternal::BasicStream* __os = __og.startWriteParams(::Ice::DefaultFormat);
        __os->write(__p_mapArg);
        __og.endWriteParams();
    }
    catch(const ::Ice::LocalException& __ex)
    {
        __og.abort(__ex);
    }
    if(!__og.invoke())
    {
        try
        {
            __og.throwUserException();
        }
        catch(const ::Ice::UserException& __ex)
        {
            ::Ice::UnknownUserException __uue(__FILE__, __LINE__, __ex.ice_name());
            throw __uue;
        }
    }
    ::Ice::Int __ret;
    ::IceInternal::BasicStream* __is = __og.startReadParams();
    __is->read(__ret);
    __og.endReadParams();
    return __ret;
}

::Ice::AsyncResultPtr
IceProxy::RPCImgRecong::ImgRetrieval::begin_imgSearchAsync(const ::RPCImgRecong::DictStr2Str& __p_mapArg, const ::Ice::Context* __ctx, const ::IceInternal::CallbackBasePtr& __del, const ::Ice::LocalObjectPtr& __cookie)
{
    __checkAsyncTwowayOnly(__RPCImgRecong__ImgRetrieval__imgSearchAsync_name);
    ::IceInternal::OutgoingAsyncPtr __result = new ::IceInternal::OutgoingAsync(this, __RPCImgRecong__ImgRetrieval__imgSearchAsync_name, __del, __cookie);
    try
    {
        __result->prepare(__RPCImgRecong__ImgRetrieval__imgSearchAsync_name, ::Ice::Normal, __ctx);
        ::IceInternal::BasicStream* __os = __result->startWriteParams(::Ice::DefaultFormat);
        __os->write(__p_mapArg);
        __result->endWriteParams();
        __result->invoke();
    }
    catch(const ::Ice::Exception& __ex)
    {
        __result->abort(__ex);
    }
    return __result;
}

#ifdef ICE_CPP11

::Ice::AsyncResultPtr
IceProxy::RPCImgRecong::ImgRetrieval::__begin_imgSearchAsync(const ::RPCImgRecong::DictStr2Str& __p_mapArg, const ::Ice::Context* __ctx, const ::IceInternal::Function<void (::Ice::Int)>& __response, const ::IceInternal::Function<void (const ::Ice::Exception&)>& __exception, const ::IceInternal::Function<void (bool)>& __sent)
{
    class Cpp11CB : public ::IceInternal::Cpp11FnCallbackNC
    {
    public:

        Cpp11CB(const ::std::function<void (::Ice::Int)>& responseFunc, const ::std::function<void (const ::Ice::Exception&)>& exceptionFunc, const ::std::function<void (bool)>& sentFunc) :
            ::IceInternal::Cpp11FnCallbackNC(exceptionFunc, sentFunc),
            _response(responseFunc)
        {
            CallbackBase::checkCallback(true, responseFunc || exceptionFunc != nullptr);
        }

        virtual void completed(const ::Ice::AsyncResultPtr& __result) const
        {
            ::RPCImgRecong::ImgRetrievalPrx __proxy = ::RPCImgRecong::ImgRetrievalPrx::uncheckedCast(__result->getProxy());
            ::Ice::Int __ret;
            try
            {
                __ret = __proxy->end_imgSearchAsync(__result);
            }
            catch(const ::Ice::Exception& ex)
            {
                Cpp11FnCallbackNC::exception(__result, ex);
                return;
            }
            if(_response != nullptr)
            {
                _response(__ret);
            }
        }
    
    private:
        
        ::std::function<void (::Ice::Int)> _response;
    };
    return begin_imgSearchAsync(__p_mapArg, __ctx, new Cpp11CB(__response, __exception, __sent));
}
#endif

::Ice::Int
IceProxy::RPCImgRecong::ImgRetrieval::end_imgSearchAsync(const ::Ice::AsyncResultPtr& __result)
{
    ::Ice::AsyncResult::__check(__result, this, __RPCImgRecong__ImgRetrieval__imgSearchAsync_name);
    ::Ice::Int __ret;
    if(!__result->__wait())
    {
        try
        {
            __result->__throwUserException();
        }
        catch(const ::Ice::UserException& __ex)
        {
            throw ::Ice::UnknownUserException(__FILE__, __LINE__, __ex.ice_name());
        }
    }
    ::IceInternal::BasicStream* __is = __result->__startReadParams();
    __is->read(__ret);
    __result->__endReadParams();
    return __ret;
}

::RPCImgRecong::ImgRes
IceProxy::RPCImgRecong::ImgRetrieval::fetchImgSearchResult(const ::RPCImgRecong::DictStr2Str& __p_mapArg, const ::Ice::Context* __ctx)
{
    __checkTwowayOnly(__RPCImgRecong__ImgRetrieval__fetchImgSearchResult_name);
    ::IceInternal::Outgoing __og(this, __RPCImgRecong__ImgRetrieval__fetchImgSearchResult_name, ::Ice::Normal, __ctx);
    try
    {
        ::IceInternal::BasicStream* __os = __og.startWriteParams(::Ice::DefaultFormat);
        __os->write(__p_mapArg);
        __og.endWriteParams();
    }
    catch(const ::Ice::LocalException& __ex)
    {
        __og.abort(__ex);
    }
    if(!__og.invoke())
    {
        try
        {
            __og.throwUserException();
        }
        catch(const ::Ice::UserException& __ex)
        {
            ::Ice::UnknownUserException __uue(__FILE__, __LINE__, __ex.ice_name());
            throw __uue;
        }
    }
    ::RPCImgRecong::ImgRes __ret;
    ::IceInternal::BasicStream* __is = __og.startReadParams();
    __is->read(__ret);
    __og.endReadParams();
    return __ret;
}

::Ice::AsyncResultPtr
IceProxy::RPCImgRecong::ImgRetrieval::begin_fetchImgSearchResult(const ::RPCImgRecong::DictStr2Str& __p_mapArg, const ::Ice::Context* __ctx, const ::IceInternal::CallbackBasePtr& __del, const ::Ice::LocalObjectPtr& __cookie)
{
    __checkAsyncTwowayOnly(__RPCImgRecong__ImgRetrieval__fetchImgSearchResult_name);
    ::IceInternal::OutgoingAsyncPtr __result = new ::IceInternal::OutgoingAsync(this, __RPCImgRecong__ImgRetrieval__fetchImgSearchResult_name, __del, __cookie);
    try
    {
        __result->prepare(__RPCImgRecong__ImgRetrieval__fetchImgSearchResult_name, ::Ice::Normal, __ctx);
        ::IceInternal::BasicStream* __os = __result->startWriteParams(::Ice::DefaultFormat);
        __os->write(__p_mapArg);
        __result->endWriteParams();
        __result->invoke();
    }
    catch(const ::Ice::Exception& __ex)
    {
        __result->abort(__ex);
    }
    return __result;
}

#ifdef ICE_CPP11

::Ice::AsyncResultPtr
IceProxy::RPCImgRecong::ImgRetrieval::__begin_fetchImgSearchResult(const ::RPCImgRecong::DictStr2Str& __p_mapArg, const ::Ice::Context* __ctx, const ::IceInternal::Function<void (const ::RPCImgRecong::ImgRes&)>& __response, const ::IceInternal::Function<void (const ::Ice::Exception&)>& __exception, const ::IceInternal::Function<void (bool)>& __sent)
{
    class Cpp11CB : public ::IceInternal::Cpp11FnCallbackNC
    {
    public:

        Cpp11CB(const ::std::function<void (const ::RPCImgRecong::ImgRes&)>& responseFunc, const ::std::function<void (const ::Ice::Exception&)>& exceptionFunc, const ::std::function<void (bool)>& sentFunc) :
            ::IceInternal::Cpp11FnCallbackNC(exceptionFunc, sentFunc),
            _response(responseFunc)
        {
            CallbackBase::checkCallback(true, responseFunc || exceptionFunc != nullptr);
        }

        virtual void completed(const ::Ice::AsyncResultPtr& __result) const
        {
            ::RPCImgRecong::ImgRetrievalPrx __proxy = ::RPCImgRecong::ImgRetrievalPrx::uncheckedCast(__result->getProxy());
            ::RPCImgRecong::ImgRes __ret;
            try
            {
                __ret = __proxy->end_fetchImgSearchResult(__result);
            }
            catch(const ::Ice::Exception& ex)
            {
                Cpp11FnCallbackNC::exception(__result, ex);
                return;
            }
            if(_response != nullptr)
            {
                _response(__ret);
            }
        }
    
    private:
        
        ::std::function<void (const ::RPCImgRecong::ImgRes&)> _response;
    };
    return begin_fetchImgSearchResult(__p_mapArg, __ctx, new Cpp11CB(__response, __exception, __sent));
}
#endif

::RPCImgRecong::ImgRes
IceProxy::RPCImgRecong::ImgRetrieval::end_fetchImgSearchResult(const ::Ice::AsyncResultPtr& __result)
{
    ::Ice::AsyncResult::__check(__result, this, __RPCImgRecong__ImgRetrieval__fetchImgSearchResult_name);
    ::RPCImgRecong::ImgRes __ret;
    if(!__result->__wait())
    {
        try
        {
            __result->__throwUserException();
        }
        catch(const ::Ice::UserException& __ex)
        {
            throw ::Ice::UnknownUserException(__FILE__, __LINE__, __ex.ice_name());
        }
    }
    ::IceInternal::BasicStream* __is = __result->__startReadParams();
    __is->read(__ret);
    __result->__endReadParams();
    return __ret;
}

::RPCImgRecong::ImgRes
IceProxy::RPCImgRecong::ImgRetrieval::imgSearchSync(const ::RPCImgRecong::DictStr2Str& __p_mapArg, const ::Ice::Context* __ctx)
{
    __checkTwowayOnly(__RPCImgRecong__ImgRetrieval__imgSearchSync_name);
    ::IceInternal::Outgoing __og(this, __RPCImgRecong__ImgRetrieval__imgSearchSync_name, ::Ice::Normal, __ctx);
    try
    {
        ::IceInternal::BasicStream* __os = __og.startWriteParams(::Ice::DefaultFormat);
        __os->write(__p_mapArg);
        __og.endWriteParams();
    }
    catch(const ::Ice::LocalException& __ex)
    {
        __og.abort(__ex);
    }
    if(!__og.invoke())
    {
        try
        {
            __og.throwUserException();
        }
        catch(const ::Ice::UserException& __ex)
        {
            ::Ice::UnknownUserException __uue(__FILE__, __LINE__, __ex.ice_name());
            throw __uue;
        }
    }
    ::RPCImgRecong::ImgRes __ret;
    ::IceInternal::BasicStream* __is = __og.startReadParams();
    __is->read(__ret);
    __og.endReadParams();
    return __ret;
}

::Ice::AsyncResultPtr
IceProxy::RPCImgRecong::ImgRetrieval::begin_imgSearchSync(const ::RPCImgRecong::DictStr2Str& __p_mapArg, const ::Ice::Context* __ctx, const ::IceInternal::CallbackBasePtr& __del, const ::Ice::LocalObjectPtr& __cookie)
{
    __checkAsyncTwowayOnly(__RPCImgRecong__ImgRetrieval__imgSearchSync_name);
    ::IceInternal::OutgoingAsyncPtr __result = new ::IceInternal::OutgoingAsync(this, __RPCImgRecong__ImgRetrieval__imgSearchSync_name, __del, __cookie);
    try
    {
        __result->prepare(__RPCImgRecong__ImgRetrieval__imgSearchSync_name, ::Ice::Normal, __ctx);
        ::IceInternal::BasicStream* __os = __result->startWriteParams(::Ice::DefaultFormat);
        __os->write(__p_mapArg);
        __result->endWriteParams();
        __result->invoke();
    }
    catch(const ::Ice::Exception& __ex)
    {
        __result->abort(__ex);
    }
    return __result;
}

#ifdef ICE_CPP11

::Ice::AsyncResultPtr
IceProxy::RPCImgRecong::ImgRetrieval::__begin_imgSearchSync(const ::RPCImgRecong::DictStr2Str& __p_mapArg, const ::Ice::Context* __ctx, const ::IceInternal::Function<void (const ::RPCImgRecong::ImgRes&)>& __response, const ::IceInternal::Function<void (const ::Ice::Exception&)>& __exception, const ::IceInternal::Function<void (bool)>& __sent)
{
    class Cpp11CB : public ::IceInternal::Cpp11FnCallbackNC
    {
    public:

        Cpp11CB(const ::std::function<void (const ::RPCImgRecong::ImgRes&)>& responseFunc, const ::std::function<void (const ::Ice::Exception&)>& exceptionFunc, const ::std::function<void (bool)>& sentFunc) :
            ::IceInternal::Cpp11FnCallbackNC(exceptionFunc, sentFunc),
            _response(responseFunc)
        {
            CallbackBase::checkCallback(true, responseFunc || exceptionFunc != nullptr);
        }

        virtual void completed(const ::Ice::AsyncResultPtr& __result) const
        {
            ::RPCImgRecong::ImgRetrievalPrx __proxy = ::RPCImgRecong::ImgRetrievalPrx::uncheckedCast(__result->getProxy());
            ::RPCImgRecong::ImgRes __ret;
            try
            {
                __ret = __proxy->end_imgSearchSync(__result);
            }
            catch(const ::Ice::Exception& ex)
            {
                Cpp11FnCallbackNC::exception(__result, ex);
                return;
            }
            if(_response != nullptr)
            {
                _response(__ret);
            }
        }
    
    private:
        
        ::std::function<void (const ::RPCImgRecong::ImgRes&)> _response;
    };
    return begin_imgSearchSync(__p_mapArg, __ctx, new Cpp11CB(__response, __exception, __sent));
}
#endif

::RPCImgRecong::ImgRes
IceProxy::RPCImgRecong::ImgRetrieval::end_imgSearchSync(const ::Ice::AsyncResultPtr& __result)
{
    ::Ice::AsyncResult::__check(__result, this, __RPCImgRecong__ImgRetrieval__imgSearchSync_name);
    ::RPCImgRecong::ImgRes __ret;
    if(!__result->__wait())
    {
        try
        {
            __result->__throwUserException();
        }
        catch(const ::Ice::UserException& __ex)
        {
            throw ::Ice::UnknownUserException(__FILE__, __LINE__, __ex.ice_name());
        }
    }
    ::IceInternal::BasicStream* __is = __result->__startReadParams();
    __is->read(__ret);
    __result->__endReadParams();
    return __ret;
}

const ::std::string&
IceProxy::RPCImgRecong::ImgRetrieval::ice_staticId()
{
    return ::RPCImgRecong::ImgRetrieval::ice_staticId();
}

::IceProxy::Ice::Object*
IceProxy::RPCImgRecong::ImgRetrieval::__newInstance() const
{
    return new ImgRetrieval;
}

::Ice::Object* RPCImgRecong::upCast(::RPCImgRecong::ImgRetrieval* p) { return p; }

namespace
{
const ::std::string __RPCImgRecong__ImgRetrieval_ids[2] =
{
    "::Ice::Object",
    "::RPCImgRecong::ImgRetrieval"
};

}

bool
RPCImgRecong::ImgRetrieval::ice_isA(const ::std::string& _s, const ::Ice::Current&) const
{
    return ::std::binary_search(__RPCImgRecong__ImgRetrieval_ids, __RPCImgRecong__ImgRetrieval_ids + 2, _s);
}

::std::vector< ::std::string>
RPCImgRecong::ImgRetrieval::ice_ids(const ::Ice::Current&) const
{
    return ::std::vector< ::std::string>(&__RPCImgRecong__ImgRetrieval_ids[0], &__RPCImgRecong__ImgRetrieval_ids[2]);
}

const ::std::string&
RPCImgRecong::ImgRetrieval::ice_id(const ::Ice::Current&) const
{
    return __RPCImgRecong__ImgRetrieval_ids[1];
}

const ::std::string&
RPCImgRecong::ImgRetrieval::ice_staticId()
{
#ifdef ICE_HAS_THREAD_SAFE_LOCAL_STATIC
    static const ::std::string typeId = "::RPCImgRecong::ImgRetrieval";
    return typeId;
#else
    return __RPCImgRecong__ImgRetrieval_ids[1];
#endif
}

::Ice::DispatchStatus
RPCImgRecong::ImgRetrieval::___wordGetKnowledge(::IceInternal::Incoming& __inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Normal, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.startReadParams();
    ::std::string __p_word;
    __is->read(__p_word);
    __inS.endReadParams();
    ::RPCImgRecong::WordWiki __ret = wordGetKnowledge(__p_word, __current);
    ::IceInternal::BasicStream* __os = __inS.__startWriteParams(::Ice::DefaultFormat);
    __os->write(__ret);
    __inS.__endWriteParams(true);
    return ::Ice::DispatchOK;
}

::Ice::DispatchStatus
RPCImgRecong::ImgRetrieval::___wordSearch(::IceInternal::Incoming& __inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Normal, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.startReadParams();
    ::RPCImgRecong::DictStr2Str __p_mapArg;
    __is->read(__p_mapArg);
    __inS.endReadParams();
    ::RPCImgRecong::WordRes __ret = wordSearch(__p_mapArg, __current);
    ::IceInternal::BasicStream* __os = __inS.__startWriteParams(::Ice::DefaultFormat);
    __os->write(__ret);
    __inS.__endWriteParams(true);
    return ::Ice::DispatchOK;
}

::Ice::DispatchStatus
RPCImgRecong::ImgRetrieval::___wordSearchImg(::IceInternal::Incoming& __inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Normal, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.startReadParams();
    ::RPCImgRecong::DictStr2Str __p_mapArg;
    __is->read(__p_mapArg);
    __inS.endReadParams();
    ::RPCImgRecong::ImgRes __ret = wordSearchImg(__p_mapArg, __current);
    ::IceInternal::BasicStream* __os = __inS.__startWriteParams(::Ice::DefaultFormat);
    __os->write(__ret);
    __inS.__endWriteParams(true);
    return ::Ice::DispatchOK;
}

::Ice::DispatchStatus
RPCImgRecong::ImgRetrieval::___imgSearchAsync(::IceInternal::Incoming& __inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Normal, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.startReadParams();
    ::RPCImgRecong::DictStr2Str __p_mapArg;
    __is->read(__p_mapArg);
    __inS.endReadParams();
    ::Ice::Int __ret = imgSearchAsync(__p_mapArg, __current);
    ::IceInternal::BasicStream* __os = __inS.__startWriteParams(::Ice::DefaultFormat);
    __os->write(__ret);
    __inS.__endWriteParams(true);
    return ::Ice::DispatchOK;
}

::Ice::DispatchStatus
RPCImgRecong::ImgRetrieval::___fetchImgSearchResult(::IceInternal::Incoming& __inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Normal, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.startReadParams();
    ::RPCImgRecong::DictStr2Str __p_mapArg;
    __is->read(__p_mapArg);
    __inS.endReadParams();
    ::RPCImgRecong::ImgRes __ret = fetchImgSearchResult(__p_mapArg, __current);
    ::IceInternal::BasicStream* __os = __inS.__startWriteParams(::Ice::DefaultFormat);
    __os->write(__ret);
    __inS.__endWriteParams(true);
    return ::Ice::DispatchOK;
}

::Ice::DispatchStatus
RPCImgRecong::ImgRetrieval::___imgSearchSync(::IceInternal::Incoming& __inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Normal, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.startReadParams();
    ::RPCImgRecong::DictStr2Str __p_mapArg;
    __is->read(__p_mapArg);
    __inS.endReadParams();
    ::RPCImgRecong::ImgRes __ret = imgSearchSync(__p_mapArg, __current);
    ::IceInternal::BasicStream* __os = __inS.__startWriteParams(::Ice::DefaultFormat);
    __os->write(__ret);
    __inS.__endWriteParams(true);
    return ::Ice::DispatchOK;
}

namespace
{
const ::std::string __RPCImgRecong__ImgRetrieval_all[] =
{
    "fetchImgSearchResult",
    "ice_id",
    "ice_ids",
    "ice_isA",
    "ice_ping",
    "imgSearchAsync",
    "imgSearchSync",
    "wordGetKnowledge",
    "wordSearch",
    "wordSearchImg"
};

}

::Ice::DispatchStatus
RPCImgRecong::ImgRetrieval::__dispatch(::IceInternal::Incoming& in, const ::Ice::Current& current)
{
    ::std::pair< const ::std::string*, const ::std::string*> r = ::std::equal_range(__RPCImgRecong__ImgRetrieval_all, __RPCImgRecong__ImgRetrieval_all + 10, current.operation);
    if(r.first == r.second)
    {
        throw ::Ice::OperationNotExistException(__FILE__, __LINE__, current.id, current.facet, current.operation);
    }

    switch(r.first - __RPCImgRecong__ImgRetrieval_all)
    {
        case 0:
        {
            return ___fetchImgSearchResult(in, current);
        }
        case 1:
        {
            return ___ice_id(in, current);
        }
        case 2:
        {
            return ___ice_ids(in, current);
        }
        case 3:
        {
            return ___ice_isA(in, current);
        }
        case 4:
        {
            return ___ice_ping(in, current);
        }
        case 5:
        {
            return ___imgSearchAsync(in, current);
        }
        case 6:
        {
            return ___imgSearchSync(in, current);
        }
        case 7:
        {
            return ___wordGetKnowledge(in, current);
        }
        case 8:
        {
            return ___wordSearch(in, current);
        }
        case 9:
        {
            return ___wordSearchImg(in, current);
        }
    }

    assert(false);
    throw ::Ice::OperationNotExistException(__FILE__, __LINE__, current.id, current.facet, current.operation);
}

void
RPCImgRecong::ImgRetrieval::__writeImpl(::IceInternal::BasicStream* __os) const
{
    __os->startWriteSlice(ice_staticId(), -1, true);
    __os->endWriteSlice();
}

void
RPCImgRecong::ImgRetrieval::__readImpl(::IceInternal::BasicStream* __is)
{
    __is->startReadSlice();
    __is->endReadSlice();
}

void 
RPCImgRecong::__patch(ImgRetrievalPtr& handle, const ::Ice::ObjectPtr& v)
{
    handle = ::RPCImgRecong::ImgRetrievalPtr::dynamicCast(v);
    if(v && !handle)
    {
        IceInternal::Ex::throwUOE(::RPCImgRecong::ImgRetrieval::ice_staticId(), v);
    }
}