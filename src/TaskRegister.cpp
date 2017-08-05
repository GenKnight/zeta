/******************************************************************************
Copyright (c) 2016. All Rights Reserved.

FileName: task_factory.h
Version: 1.0
Date: 2017.8.5

History:
eric     2017.8.5   1.0     Create
******************************************************************************/

#include "TaskRegister.h"
#include "TaskInterfaceDef.h"
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
		APP_REGISTER *ptrData;

		ASSET_MESSAGE_STRUCT Msg;
		TCP_MSG_HEAD header;

		task_desc_.get_task_message( Msg );

		header.datatype = Msg.header.datatype;
		header.datasize = sizeof(int);

		if ( Msg.ptrData==NULL || Msg.header.datasize!=sizeof(APP_REGISTER) || Msg.header.datatype!=1 )
		{
			return -1;
		}

		ptrData = (APP_REGISTER *)(Msg.ptrData);

		try
		{
			APP_LOG(utility::applog::LOG_INFO) << "task register: " << ptrData->num;
            APP_REGISTER sp = { 0 };
            sp.num = 1;
            get_server().send_messages(1, (const char*)&sp, header);
		}
		catch( ... )
		{
			return -1;
		}

		return 0;
	}
} 