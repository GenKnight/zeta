/******************************************************************************
Copyright (c) 2016. All Rights Reserved.

FileName: amq_engine.h
Version: 1.0
Date: 2017.8.5

History:
eric     2017.8.5   1.0     Create
******************************************************************************/

#include "AmqEngine.h"

namespace zeta
{
AmqEngine::AmqEngine()
{
    m_amq_req = nullptr;
    m_amq_rsp = nullptr;
}

AmqEngine::~AmqEngine()
{
	Stop();
}

void AmqEngine::Init(IAmqAsyncConsumerNotify& ts_notify)
{
	std::string amq_addr = "127.0.0.1:61616";

	//std::string rsp_server = "Q.ERIC2TOM";
 //   m_amq_rsp = AmqCreateProducer(amq_addr.c_str(), rsp_server.c_str());
 //   m_amq_rsp->AmqStart();

	//std::string req_server = "Q.TOM2ERIC";
 //   m_amq_req = AmqCreateAsyncConsumer(&ts_notify, amq_addr.c_str(), req_server.c_str());
 //   m_amq_req->AmqStart();
	
	Sleep(1000);	// 等待1秒
}


////////////////////////////////////////////////////////////////////////////////
void AmqEngine::Stop()
{
	// 先删除消费者再删除生产者
    if (m_amq_req != NULL)
	{
        AmqDeleteAsyncConsumer(m_amq_req);
        m_amq_req = NULL;
	}
    if (m_amq_rsp != NULL)
	{
        AmqDeleteProducer(m_amq_rsp);
        m_amq_rsp = NULL;
	}
}

IAmqProducer& AmqEngine::GetTradeServer()
{
    if (m_amq_rsp == nullptr)
	{
		throw std::logic_error("m_amq_future_ctpts_rsp is null ptr.");
	}
    return *m_amq_rsp;
}

}
