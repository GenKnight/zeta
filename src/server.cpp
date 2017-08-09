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
#include "../proto/protocal.pb.h"
#include "../proto/parse.h"
namespace zeta 
{
	void server::start_server()
	{
        m_bstop = false;
        m_message_server.run(2);
        start();

        session client;
        zeta::login_info msg;
        msg.mutable_head()->set_size(10001);
        msg.mutable_head()->set_type(10002);
        msg.set_userid(10003);
        msg.set_pwd("123456");
        msg.add_record("one");
        msg.add_record("two");
        msg.add_record("three");
        string result;
        encode(result, msg);
        MESSAGE_HEAD header;
        header.datasize = result.size();
        header.datatype = 2;
        client.on_notify(result.c_str(), header);

	}

	void server::stop_server()
	{
        m_bstop = true;
	}

	void server::send_messages( int type, const char* stream, MESSAGE_HEAD &header )
	{
		switch(type)
		{
		case 1:
			{
				break;
			}			
		default:
			{
				break;
			}
		}
	}

	void server::run()
	{
        while (!m_bstop)
		{
			q_sleep(1000);
		}
	}
}
