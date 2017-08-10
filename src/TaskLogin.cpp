/******************************************************************************
Copyright (c) 2016. All Rights Reserved.

FileName: task_factory.h
Version: 1.0
Date: 2017.8.5

History:
eric     2017.8.5   1.0     Create
******************************************************************************/

#include "TaskLogin.h"
#include "task_interface.h"
#include "server.h"
#include <memory>
#include "proto/parse.h"
#include "proto/protocal.pb.h"
#include <iostream>
namespace zeta 
{

	CTaskLogin::CTaskLogin( task_data task_desc)
        :engine_task(task_desc)
	{
		
	}

	CTaskLogin::~CTaskLogin(void)
	{
	}

	//@brief    : execute implement method, implement task execute operator
	//@return   : return 0 if success, or -1 if failed
	int CTaskLogin::execute_impl()
	{
		MESSAGE_STRUCT Msg;
		MESSAGE_HEAD header;

		task_desc_.get_task_message( Msg );

		header.datatype = Msg.header.datatype;
		header.datasize = sizeof(int);
        int32_t len = asInt32((const char*)Msg.ptrData);
        string read_msg;
        read_msg.resize(len);
        memcpy(&read_msg[0], 
            (const char*)Msg.ptrData+sizeof(int32_t),
            len);
		try
		{
            std::shared_ptr<google::protobuf::Message> 
                msg_ptr(decode(read_msg));

            google::protobuf::Message* pMsg = msg_ptr.get();
            if (pMsg && pMsg->GetDescriptor() == zeta::login_info::descriptor()) {
                zeta::login_info* pReq = dynamic_cast<zeta::login_info*>(pMsg);
                cout << pReq->mutable_head()->size() << endl;
                cout << pReq->userid() << endl;
                cout << pReq->pwd() << endl;
                for (int i = 0; i < pReq->record_size(); i++) {
                    cout << pReq->record(i) << endl;
                }

                string pwd = pReq->pwd();
                header.datasize = pwd.size();
                get_server().send_messages(1, pwd.c_str(), header);
            }
		}
		catch( ... )
		{
			return -1;
		}

		return 0;
	}
} 