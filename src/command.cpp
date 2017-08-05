/******************************************************************************
Copyright (c) 2016. All Rights Reserved.

FileName: command.h
Version: 1.0
Date: 2017.8.5

History:
eric     2017.8.5   1.0     Create
******************************************************************************/


#include "command.h"

namespace zeta 
{

void command::exe_command_impl()
{  
    for (auto it = tasks_.begin(); it != tasks_.end(); it++) {
		std::shared_ptr<engine_task> task_ptr = it->second;
        task_ptr->execute_impl();
    }
}

} // namespace itstation 

