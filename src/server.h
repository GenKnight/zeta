/******************************************************************************
Copyright (c) 2016. All Rights Reserved.

FileName: server.h
Version: 1.0
Date: 2017.8.5

History:
eric     2017.8.5   1.0     Create
******************************************************************************/

#ifndef __SERVER_H__
#define __SERVER_H__

#include <iostream>
#include <string>
#include <string.h>
#include "utility/singleton.h"
#include "utility/mutex.h"
#include "session.h"
#include "message_server.h"
#include "task_data.h"
namespace zeta 
{
	class server
	{ 
        SINGLETON_ONCE_UNINIT(server);
        server(){};
    public:
        ~server(){ stop(); }
	public:
        void run(const size_t thread_num);
        void join();
		void stop();

		void send_messages( int type, const char* stream, MESSAGE_HEAD &header );

        void post(MESSAGE_STRUCT &msg)
        {
            m_message_server.post(msg);
        }
	private: 
        session m_notify;
        message_server<MESSAGE_STRUCT> m_message_server;
	}; 
    SINGLETON_GET(server);

}
#endif
