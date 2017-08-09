/******************************************************************************
Copyright (c) 2016. All Rights Reserved.

FileName: amq_engine.h
Version: 1.0
Date: 2017.8.5

History:
eric     2017.8.5   1.0     Create
******************************************************************************/

#ifndef __AMQ_ENGINE_H__
#define __AMQ_ENGINE_H__

#include "fndcms/fndcms.h"
#include "utility/singleton.h"
namespace zeta
{
class AmqEngine
{
    SINGLETON_ONCE_UNINIT(AmqEngine);
	AmqEngine();
public:
	~AmqEngine();

	// 初始化消息队列
	void Init(IAmqAsyncConsumerNotify& ts_notify);

	IAmqProducer& GetTradeServer();
	void Stop();

private:
    IAmqProducer* m_amq_rsp;
    IAmqAsyncConsumer* m_amq_req;
};
SINGLETON_GET(AmqEngine);

}
#endif