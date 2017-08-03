
#include "TaskFactory.h"
#include "TaskRegister.h"
#include "TaskLogin.h"

namespace itstation 
{
	TaskID TaskFactory::TaskCodeToTaskID(const int& code) 
    {
		switch ( code )
		{
		case 1:	//APP用户注册
			return eRegister;	
		case 2://APP用户登录
			return eLogin;      
		default:
			return eUnknownTaskID;
		}
	}

	std::shared_ptr<EngineTask> TaskFactory::createEngineTask(ASSET_MESSAGE_STRUCT Message) {	
		int id = Message.header.datatype;
		TaskID t = TaskCodeToTaskID( id );
		std::shared_ptr<TaskData> taskData(new TaskData());
		taskData->set_task_message( Message );

		switch (t) {
		case eRegister:
			return std::shared_ptr<EngineTask>(new CTaskRegister(*taskData));

		case eLogin:
			return std::shared_ptr<EngineTask>(new CTaskLogin(*taskData));

		default:
			{

			}
		}
		return std::shared_ptr<EngineTask>((EngineTask *)0);
	}

} //namespace itstation 
