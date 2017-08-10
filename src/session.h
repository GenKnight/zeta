/******************************************************************************
Copyright (c) 2016. All Rights Reserved.

FileName: session.h
Version: 1.0
Date: 2017.8.5

History:
eric     2017.8.5   1.0     Create
******************************************************************************/

#ifndef __SESSION_H__
#define __SESSION_H__
#include "task_data.h"
#include "fndcms/fndcms.h"
namespace zeta 
{
    class session
        : public IAmqAsyncConsumerNotify
    {
    public:

        explicit session();
        virtual ~session();

        virtual void OnMessageText(const char* usrid, int type, const char* text){}
        virtual void OnMessageStream(const char* stream, CMS_HEADER &header) override;
        virtual void OnTransportInterrupted(){}
        virtual void OnTransportResumed(){}
	};
} 
#endif
