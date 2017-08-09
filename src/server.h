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
#include "utility/thread.h"
#include "session.h"

namespace zeta 
{
	class server
        : public utility::thread
	{ 
        SINGLETON_ONCE_UNINIT(server);
        server(){};
    public:
        ~server(){ stop_server(); }
	public:
		void start_server();
		void stop_server();

		void send_messages( int type, const char* stream, MESSAGE_HEAD &header );

		//Implement Thread "run" interface
		virtual void run();

	private: 
		bool m_bstop;
	}; 
    SINGLETON_GET(server);

}
#endif
