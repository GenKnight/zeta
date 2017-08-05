/******************************************************************************
Copyright (c) 2016. All Rights Reserved.

FileName: command.h
Version: 1.0
Date: 2017.8.5

History:
eric     2017.8.5   1.0     Create
******************************************************************************/

#ifndef WORKPLAN_REQUESTCOMMAND_H
#define WORKPLAN_REQUESTCOMMAND_H

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

		map<int, std::shared_ptr<engine_task> > tasks_;

	private:

	};


} // namespace itstation 
#endif
