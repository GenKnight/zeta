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
#include "TcpMsgHead.h"

typedef struct ASSET_MESSAGE_STRUCT
{
	TCP_MSG_HEAD header;
	void *ptrData;

}ASSET_MESSAGE_STRUCT;

class task_data
{
public:
    task_data() { }
    virtual ~task_data() { }

	void set_task_message( ASSET_MESSAGE_STRUCT &msg );
	void get_task_message( ASSET_MESSAGE_STRUCT &msg );
private:
	ASSET_MESSAGE_STRUCT m_Data;
};

inline void task_data::set_task_message(ASSET_MESSAGE_STRUCT &msg)
{
	m_Data.header	= msg.header;
	m_Data.ptrData	= msg.ptrData;
}

inline void task_data::get_task_message(ASSET_MESSAGE_STRUCT &msg)
{
	msg.header	= m_Data.header;
	msg.ptrData = m_Data.ptrData;
}

#endif
