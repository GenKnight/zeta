/******************************************************************************
Copyright (c) 2016. All Rights Reserved.

FileName: engine_task.h
Version: 1.0
Date: 2017.8.5

History:
eric     2017.8.5   1.0     Create
******************************************************************************/

#ifndef __ENGINETASK_H__
#define __ENGINETASK_H__

#include "task_data.h"
#include <string>
#include <vector>
#include <list>
#ifdef __GNUG__
#include <sys/time.h>	
#endif
using namespace std;

namespace zeta
{
	class engine_task
    {
	public:
        engine_task(){};
        engine_task(task_data task_desc);
        virtual ~engine_task();

		virtual int execute_impl() = 0;

        task_data task_desc_;
	};
} 
#endif
