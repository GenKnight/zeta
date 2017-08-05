/******************************************************************************
Copyright (c) 2016. All Rights Reserved.

FileName: task_factory.h
Version: 1.0
Date: 2017.8.5

History:
eric     2017.8.5   1.0     Create
******************************************************************************/

#ifndef WORKPLAN_TASK_LOGIN_H_
#define WORKPLAN_TASK_LOGIN_H_

#include "engine_task.h"

namespace zeta 
{
	class CTaskLogin :
        public engine_task
	{
	public:
		CTaskLogin(void){};
		explicit CTaskLogin( task_data task_desc);

		virtual ~CTaskLogin(void);

		//@brief    : execute implement method, implement task execute operator
		//@return   : return 0 if success, or -1 if failed
		virtual int execute_impl();
	};

} //namespace itstation 
#endif

