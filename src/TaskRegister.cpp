#include "TaskRegister.h"
#include "TaskInterfaceDef.h"
#include "ProjectServer.h"
#include "utility/applog.h"
namespace itstation 
{

	CTaskRegister::CTaskRegister( TaskData task_desc)
		:EngineTask(task_desc)
	{
	}


	CTaskRegister::~CTaskRegister(void)
	{
	}

	//@brief    : execute implement method, implement task execute operator
	int CTaskRegister::executeImpl()
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
            get_CProjectServer().SendMessages(1, (const char*)&sp, header);
		}
		catch( ... )
		{
			return -1;
		}

		return 0;
	}
} //namespace itstation 