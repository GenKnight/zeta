#include "ProjectServer.h"
#include "utility/applog.h"
#include "TaskInterfaceDef.h"
#include "ClientSession.h"
#include "../proto/protocal.pb.h"
#include "../proto/parse.h"
namespace itstation 
{
	void CProjectServer::startServer()
	{
        m_bstop = false;
        start();

        ClientSession session;
        zeta::login_info msg;
        msg.mutable_head()->set_size(10001);
        msg.mutable_head()->set_type(10002);
        msg.set_userid(10003);
        msg.set_pwd("123456");
        string result;
        encode(result, msg);
        TCP_MSG_HEAD header;
        header.datasize = result.size();
        header.datatype = 2;
        session.OnMessageStream(result.c_str(), header);

	}

	void CProjectServer::stopServer()
	{
        m_bstop = true;
	}

	void CProjectServer::SendMessages( int type, const char* stream, TCP_MSG_HEAD &header )
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

	void CProjectServer::run()
	{
        while (!m_bstop)
		{
			q_sleep(1000);
		}
	}
}
