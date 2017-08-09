/******************************************************************************
Copyright (c) 2016. All Rights Reserved.

FileName: parser.h
Version: 1.0
Date: 2017.8.5

History:
eric     2017.8.5   1.0     Create
******************************************************************************/

#ifndef __PARSER_H__
#define __PARSER_H__

#include "command.h"
namespace zeta 
{
	class parser 
	{
	public:
        parser(){};
        virtual ~parser(){};

		int parse_taskgroup(MESSAGE_STRUCT Message, command& cmd);
	private:

	};
} // namespace WorkPlan
#endif
