/******************************************************************************
Copyright (c) 2016. All Rights Reserved.

FileName: task_factory.h
Version: 1.0
Date: 2017.8.5

History:
eric     2017.8.5   1.0     Create
******************************************************************************/

#ifndef __TASK_FACTORY_H__
#define __TASK_FACTORY_H__
#include <memory>
#include "utility/singleton.h"
#include "engine_task.h"

namespace zeta 
{
	/*
	*task enum list -- APP请求命令类型定义
	*/
	enum TASKID{
        e_register = 1,     //用户注册
        e_login = 2,        //用户登录
        e_unknown = 9999
	};
//简单工厂模式
class taskfactory {
    SINGLETON_ONCE(taskfactory);

    TASKID get_taskid(const int& code);
public:
    std::shared_ptr<engine_task> create_enginetask(MESSAGE_STRUCT message);

};
SINGLETON_GET(taskfactory);

} 
#endif
