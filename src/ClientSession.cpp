#include <iostream>
#include <memory>
#include "ClientSession.h"
#include "RequestCMDParser.h"
#include "RequestCommand.h"
#include "utility/applog.h"
#include <string.h>

#ifndef _WIN32
#include <sys/time.h>
#endif

namespace itstation {
	ClientSession::ClientSession( int nType )  
		:m_nType(nType)
	{    

	}

	ClientSession::~ClientSession() 
	{
		APP_LOG(utility::applog::LOG_INFO) << __FUNCTION__;
	}


#ifndef _WIN32
	int timeval_subtract(struct timeval* result, struct timeval* x, struct timeval* y) 
	{ 
		int nsec; 

		if ( x->tv_sec>y->tv_sec ) 
			return -1; 

		if ( (x->tv_sec==y->tv_sec) && (x->tv_usec>y->tv_usec) ) 
			return -1; 

		result->tv_sec = ( y->tv_sec-x->tv_sec ); 
		result->tv_usec = ( y->tv_usec-x->tv_usec ); 

		if (result->tv_usec<0) 
		{ 
			result->tv_sec--; 
			result->tv_usec+=1000000; 
		} 

		return 0; 
	}
#endif

	void ClientSession::OnMessageStream( const char* stream, TCP_MSG_HEAD &header )
	{ 
		int nDataSize = header.datasize;

		if ( nDataSize<1 ) {
			APP_LOG(utility::applog::LOG_ERROR) << "Recv stream msg error!";
			return;
		}
#ifndef _WIN32	//测试性能
		struct timeval start,stop,diff; 
		gettimeofday(&start,0); 
#endif

		ASSET_MESSAGE_STRUCT message;

		message.header.datatype			= header.datatype;
		message.header.datasize			= nDataSize;
		message.ptrData					= new char[nDataSize];
        memcpy(message.ptrData, stream, nDataSize);

        std::shared_ptr<RequestCMDParser> cmdParse(new RequestCMDParser());
        std::shared_ptr<RequestCommand> command(new RequestCommand());

        try {
            cmdParse->parseTaskGroup(message, *command);
        }
        catch (...) {
            APP_LOG(utility::applog::LOG_CRITICAL) << "Fatal Error, Task Can not find！" << header.datatype;
            return;
        }

        command->exeCommandImpl();

        delete[] message.ptrData;
        message.ptrData = NULL;
#ifndef _WIN32	//测试性能
		gettimeofday(&stop,0); 
		timeval_subtract(&diff,&start,&stop); 
		printf( "Task [ datatype=%d ]. Time elapsed:%d(us)\n", message.header.datatype, diff.tv_usec );
#endif
	}

} // namespace WorkPlan

