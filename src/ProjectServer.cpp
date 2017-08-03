#include "ProjectServer.h"
#include "utility/applog.h"
#include "TaskInterfaceDef.h"
namespace itstation 
{
	void CProjectServer::startServer()
	{
        m_bstop = false;

		start();
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
