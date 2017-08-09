/******************************************************************************
Copyright (c) 2016. All Rights Reserved.

FileName: session.cpp
Version: 1.0
Date: 2017.8.5

History:
eric     2017.8.5   1.0     Create
******************************************************************************/

#include <iostream>
#include <memory>
#include "session.h"
#include "parser.h"
#include "command.h"
#include "utility/applog.h"
#include <string.h>

#ifndef _WIN32
#include <sys/time.h>
#endif

#ifndef _WIN32
int timeval_subtract(struct timeval* result, struct timeval* x, struct timeval* y)
{
    int nsec;

    if (x->tv_sec > y->tv_sec)
        return -1;

    if ((x->tv_sec == y->tv_sec) && (x->tv_usec > y->tv_usec))
        return -1;

    result->tv_sec = (y->tv_sec - x->tv_sec);
    result->tv_usec = (y->tv_usec - x->tv_usec);

    if (result->tv_usec < 0) {
        result->tv_sec--;
        result->tv_usec += 1000000;
    }

    return 0;
}
#endif

namespace zeta
{
    session::session()
	{
	}

    session::~session()
	{
	}

	void session::on_notify( const char* stream, MESSAGE_HEAD &header )
	{
		int size = header.datasize;

		if ( size < 1 ) {
			APP_LOG(utility::applog::LOG_ERROR) << "recv stream msg error!";
			return;
		}
#ifndef _WIN32	//��������
		struct timeval start,stop,diff; 
		gettimeofday(&start,0); 
#endif

		MESSAGE_STRUCT message;

		message.header.datatype			= header.datatype;
		message.header.datasize			= size;
		message.ptrData					= new char[size];
        memcpy(message.ptrData, stream, size);

        std::shared_ptr<parser> cmdParse(new parser());
        std::shared_ptr<command> command(new command());

        try {
            cmdParse->parse_taskgroup(message, *command);
        }
        catch (...) {
            APP_LOG(utility::applog::LOG_CRITICAL) << "Fatal Error, Task Can not find��" << header.datatype;
            return;
        }
        command->exe_command_impl();

        delete[] message.ptrData;
        message.ptrData = NULL;
#ifndef _WIN32	//��������
		gettimeofday(&stop,0); 
		timeval_subtract(&diff,&start,&stop); 
		printf( "Task [ datatype=%d ]. Time elapsed:%d(us)\n", message.header.datatype, diff.tv_usec );
#endif
	}

}
