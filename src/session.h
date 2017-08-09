/******************************************************************************
Copyright (c) 2016. All Rights Reserved.

FileName: session.h
Version: 1.0
Date: 2017.8.5

History:
eric     2017.8.5   1.0     Create
******************************************************************************/

#ifndef __SESSION_H__
#define __SESSION_H__
#include "task_data.h"
namespace zeta 
{
	class session 
	{
	public:

        explicit session();
        virtual ~session();

		virtual void on_notify( const char* stream, MESSAGE_HEAD &header );
	};
} 
#endif
