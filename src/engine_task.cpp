/******************************************************************************
Copyright (c) 2016. All Rights Reserved.

FileName: engine_task.cpp
Version: 1.0
Date: 2017.8.5

History:
eric     2017.8.5   1.0     Create
******************************************************************************/

#include "engine_task.h"

namespace zeta
{
    engine_task::engine_task(task_data task_desc)
	{
		task_desc_ = task_desc;
	}

    engine_task::~engine_task()
	{
	}

}
