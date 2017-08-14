/******************************************************************************
Copyright (c) 2016. All Rights Reserved.

FileName: command.h
Version: 1.0
Date: 2017.8.5

History:
eric     2017.8.5   1.0     Create
******************************************************************************/

#ifndef __COMMAND_H__
#define __COMMAND_H__

#include "engine_task.h"
#include <memory>
#include <map>

using namespace std;

namespace zeta 
{

	class command {
	public:
        command(){};
        virtual ~command(){};

        void exe_command_impl();

		//map<int, std::shared_ptr<engine_task> > tasks_;
        std::shared_ptr<engine_task> m_task;
	private:

	};


} // namespace itstation 
#endif
