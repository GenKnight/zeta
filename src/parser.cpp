/******************************************************************************
Copyright (c) 2016. All Rights Reserved.

FileName: parser.cpp
Version: 1.0
Date: 2017.8.5

History:
eric     2017.8.5   1.0     Create
******************************************************************************/

#include <memory>
#include "parser.h"
#include "task_factory.h"
#include "engine_task.h"
namespace zeta 
{
    int parser::parse_taskgroup(ASSET_MESSAGE_STRUCT message, command& cmd)
	{
        std::shared_ptr<engine_task> task(
            get_taskfactory().create_enginetask(message));
		if(task == nullptr) {
			throw "unknown task id";
		}
        cmd.tasks_[message.header.datatype] = task;
		return 0;
	}
}
