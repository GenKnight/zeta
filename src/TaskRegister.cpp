/******************************************************************************
Copyright (c) 2016. All Rights Reserved.

FileName: task_factory.h
Version: 1.0
Date: 2017.8.5

History:
eric     2017.8.5   1.0     Create
******************************************************************************/

#include "TaskRegister.h"
#include "task_interface.h"
#include "server.h"
#include "utility/applog.h"
namespace zeta 
{

	CTaskRegister::CTaskRegister( task_data task_desc)
		:engine_task(task_desc)
	{
	}


	CTaskRegister::~CTaskRegister(void)
	{
	}

	int CTaskRegister::execute_impl()
	{
		REQ_REGISTER *ptrData;

		MESSAGE_STRUCT Msg;
		MESSAGE_HEAD header;

		task_desc_.get_task_message( Msg );

		header.datatype = Msg.header.datatype;
		header.datasize = sizeof(int);

        if (Msg.ptrData == NULL 
            || Msg.header.datasize != sizeof(RSP_REGISTER) 
            || Msg.header.datatype != 1)
		{
			return -1;
		}

        ptrData = (REQ_REGISTER *)(Msg.ptrData);

		try
		{
            RSP_REGISTER sp = { 0 };
            sp.success = 0;
            get_server().send_messages(1, (const char*)&sp, header);
		}
		catch( ... )
		{
			return -1;
		}

		return 0;
	}
} 