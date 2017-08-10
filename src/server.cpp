/******************************************************************************
Copyright (c) 2016. All Rights Reserved.

FileName: server.cpp
Version: 1.0
Date: 2017.8.5

History:[
eric     2017.8.5   1.0     Create
******************************************************************************/

#include "server.h"
#include "utility/applog.h"
#include "task_interface.h"
#include "session.h"
#include "AmqEngine.h"
#include "../proto/protocal.pb.h"
#include "../proto/parse.h"
namespace zeta 
{
    void server::run(const size_t thread_num)
	{
        m_message_server.run(thread_num);
        get_AmqEngine().Init(m_notify);
        
//for test
        //zeta::login_info msg;
        //msg.mutable_head()->set_size(10001);
        //msg.mutable_head()->set_type(10002);
        //msg.set_userid(10003);
        //msg.set_pwd("123456");
        //msg.add_record("one");
        //msg.add_record("two");
        //msg.add_record("three");
        //string result;
        //encode(result, msg);
        //MESSAGE_HEAD header;
        //header.datasize = result.size();
        //header.datatype = 2;
        //m_notify.OnMessageStream(result.c_str(), header);

	}

    void server::join()
    {
        m_message_server.join();
    }

	void server::stop()
	{
        m_message_server.stop();
	}

	void server::send_messages( int type, const char* stream, MESSAGE_HEAD &header )
	{
		switch(type)
		{
		case 1:
			{
                  get_AmqEngine().GetTradeServer().AmqSendStream(stream, header);
				break;
			}			
		default:
			{
				break;
			}
		}
	}
}
