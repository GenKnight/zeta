////////////////////////////////////////////////////////////////////////////////
/// Copyright (c) 2011, Shanghai Flagship Prime Brokerage Technology LTD
/// All rights reserved.
///
/// Create engine task based on task id;
///
/// @version $Id: TaskFactory.h 1068 2012-02-14 07:46:19Z liuzq $
////////////////////////////////////////////////////////////////////////////////

#ifndef WORKPLAN_TASKFACTORY_H
#define WORKPLAN_TASKFACTORY_H
#include <memory>
#include "utility/singleton.h"
#include "EngineTask.h"

namespace itstation 
{
	/*
	*task enum list -- APP�����������Ͷ���
	*/
	enum TaskID{
		eRegister = 1,		//�û�ע��
		eLogin = 2,			//�û���¼
		eUnknownTaskID = 9999
	};
//�򵥹���ģʽ
class TaskFactory {
    SINGLETON_ONCE(TaskFactory);

	TaskID TaskCodeToTaskID(const int& code);
public:
	std::shared_ptr<EngineTask> createEngineTask(ASSET_MESSAGE_STRUCT Message);

};
SINGLETON_GET(TaskFactory);

} //namespace itstation 
#endif
