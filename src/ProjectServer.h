#ifndef WORKPLAN_PROJECT_SERVER_H_
#define WORKPLAN_PROJECT_SERVER_H_

#include <iostream>
#include <string>
#include <string.h>
#include "utility/singleton.h"
#include "utility/mutex.h"
#include "utility/thread.h"
#include "ClientSession.h"

namespace itstation 
{
	class CProjectServer
        : public utility::thread
	{ 
        SINGLETON_ONCE_UNINIT(CProjectServer);
        CProjectServer(){};
    public:
        ~CProjectServer(){ stopServer(); }
	public:
		void startServer();
		void stopServer();

		void SendMessages( int type, const char* stream, TCP_MSG_HEAD &header );

		//Implement Thread "run" interface
		virtual void run();

	private: 
		bool m_bstop;
		//config_file_path path
		std::string config_file_path;
	}; 
    SINGLETON_GET(CProjectServer);

}
#endif
