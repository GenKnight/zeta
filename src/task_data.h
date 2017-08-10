/******************************************************************************
Copyright (c) 2016. All Rights Reserved.

FileName: task_data.h
Version: 1.0
Date: 2017.8.5

History:
eric     2017.8.5   1.0     Create
******************************************************************************/

#ifndef __TASK_DATA_H__
#define __TASK_DATA_H__
#include <string>
#include "fndcms/fndcms.h"

typedef CMS_HEADER MESSAGE_HEAD;

typedef struct message_struct
{
    MESSAGE_HEAD header;
	void *ptrData;

}MESSAGE_STRUCT;

class task_data
{
public:
    task_data() { }
    virtual ~task_data() { }

    void set_task_message(MESSAGE_STRUCT &msg);
    void get_task_message(MESSAGE_STRUCT &msg);
private:
    MESSAGE_STRUCT m_Data;
};

inline void task_data::set_task_message(MESSAGE_STRUCT &msg)
{
	m_Data.header	= msg.header;
	m_Data.ptrData	= msg.ptrData;
}

inline void task_data::get_task_message(MESSAGE_STRUCT &msg)
{
	msg.header	= m_Data.header;
	msg.ptrData = m_Data.ptrData;
}

#endif
