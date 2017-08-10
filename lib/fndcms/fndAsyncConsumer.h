#ifndef __CONSUMER_H__
#define __CONSUMER_H__

#include <decaf/lang/Thread.h>
#include <decaf/lang/Runnable.h>
#include <decaf/util/concurrent/CountDownLatch.h>
#include <activemq/core/ActiveMQConnectionFactory.h>
#include <activemq/core/ActiveMQConnection.h>
#include <activemq/transport/DefaultTransportListener.h>
#include <activemq/library/ActiveMQCPP.h>
#include <decaf/lang/Integer.h>
#include <activemq/util/Config.h>
#include <decaf/util/Date.h>
#include <cms/Connection.h>
#include <cms/Session.h>
#include <cms/TextMessage.h>
#include <cms/BytesMessage.h>
#include <cms/MapMessage.h>
#include <cms/ExceptionListener.h>
#include <cms/MessageListener.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>

#include "fndcms.h"

using namespace activemq;
using namespace activemq::core;
using namespace activemq::transport;
using namespace decaf::lang;
using namespace decaf::util;
using namespace decaf::util::concurrent;
using namespace cms;
using namespace std;

class AmqAsyncConsumer : 
    public ExceptionListener, 
    public MessageListener, 
    public DefaultTransportListener, 
    public IAmqAsyncConsumer
{
public:
    AmqAsyncConsumer(  IAmqAsyncConsumerNotify *AsyncConsumerNotify, 
        const std::string& brokerURI, const std::string& destURI, bool bUseTopic=false )
        :m_ptrAsyncConsumerNotify(AsyncConsumerNotify),
        connection(NULL),
        session(NULL),
        destination(NULL),
        consumer(NULL),
        brokerURI(brokerURI),
        destURI(destURI),
        useTopic(bUseTopic),
        clientAck(false)
    {
    }
    virtual ~AmqAsyncConsumer()
    {
        cleanup();
    }
    virtual void AmqStart();
	virtual void onCommand( const Pointer<Command> command AMQCPP_UNUSED );
    virtual void onMessage( const Message* message );
    virtual void onException( const CMSException& ex AMQCPP_UNUSED );
    virtual void transportInterrupted();
    virtual void transportResumed();

private:
    void runConsumer();
    void cleanup();

private:
	IAmqAsyncConsumerNotify *m_ptrAsyncConsumerNotify;

    Connection* connection;
    Session* session;
    Destination* destination;
    MessageConsumer* consumer;
    std::string brokerURI;
    std::string destURI;
    bool useTopic;
    bool clientAck;
};

#endif
