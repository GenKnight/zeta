/******************************************************************************
Copyright (c) 2016. All Rights Reserved.

FileName: task_factory.cpp
Version: 1.0
Date: 2017.8.5

History:
eric     2017.8.5   1.0     Create
******************************************************************************/

#include "task_factory.h"
#include "TaskRegister.h"
#include "TaskLogin.h"

namespace zeta 
{
    TASKID taskfactory::get_taskid(const int& code)
    {
		switch ( code )
		{
		case 1:
			return e_register;	
		case 2://APPÓÃ»§µÇÂ¼
            return e_login;
		default:
            return e_unknown;
		}
	}

    std::shared_ptr<engine_task> taskfactory::create_enginetask(
        ASSET_MESSAGE_STRUCT message) {
        int id = message.header.datatype;
		TASKID t = get_taskid( id );
		std::shared_ptr<task_data> data(new task_data());
        data->set_task_message(message);

		switch (t) {
		case e_register:
            return std::shared_ptr<engine_task>(new CTaskRegister(*data));
		case e_login:
            return std::shared_ptr<engine_task>(new CTaskLogin(*data));
		default:
			{
			}
		}
        return std::shared_ptr<engine_task>((engine_task *)0);
	}

}
