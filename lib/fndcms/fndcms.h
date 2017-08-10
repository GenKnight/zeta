#ifndef __FNDCMS__
#define __FNDCMS__

#include <string>

#ifndef _WIN32
#define EXPORT_INTERFACE_CLASS
#else
#ifdef EXPORT_DLL_CLASS 
#define EXPORT_INTERFACE_CLASS _declspec(dllexport)
#else
#define EXPORT_INTERFACE_CLASS _declspec(dllimport)
#endif
#endif
//#define EXPORT_INTERFACE_CLASS
typedef struct cms_head
{
	int datasize;
	int datatype;

    cms_head() 
        : datasize(0)
        , datatype(0)
	{
	}
}CMS_HEADER;

/**
* 
* Create producer
*
*/
class EXPORT_INTERFACE_CLASS IAmqProducer
{

public:

	virtual ~IAmqProducer(){};

	/**
     * Start producer
     *
     * @since 1.0
     */
	virtual void AmqStart() = 0;

	/**
     * Send text data to broker
     * @text 
	 *		to be delivered messages.
     *
     * @since 1.0
     */
	virtual void AmqSendText( const char* text, const char* usrid=NULL ) = 0;

	/**
     * Send binary data to broker
     * @stream 
     *      The binary stream message to be sent.
	 * @header 
	 *		The information of delivered messages.
    * @param llTimeToLive
     *      The time to live value for this message in milliseconds.
     * @param nDeliveryMode
     *      The delivery mode to be used(PERSISTENT = 0,NON_PERSISTENT = 1).
     * @param nPriority
     *      The priority for this message(0-lowest,..., 9-highest).
     *
     * @since 1.0
     */
	virtual void AmqSendStream( const char* stream, CMS_HEADER &header ) = 0;
	virtual void AmqSendStream( const char* stream, CMS_HEADER &header, long long llTimeToLive/*=0*/, int nDeliveryMode/*=1*/, int nPriority/*=4*/ ) = 0;
};

extern "C"
{
	/**
     * Create one instantce of ActiveMQ producer
     *  
	 *
     *
     * @since 1.0
     */
    EXPORT_INTERFACE_CLASS IAmqProducer * AmqCreateProducer(const char * amqAddress = NULL, const char * cmsQueueOrTopicName = NULL, bool bUseTopic = false);

	EXPORT_INTERFACE_CLASS void AmqDeleteProducer( IAmqProducer * &producer );
}

/**
* 
* Create Synchronous consumer -- Not support temporarily.
*
*/

class EXPORT_INTERFACE_CLASS IAmqSyncConsumer
{
public:
	virtual ~IAmqSyncConsumer(){};

	/**
     * Start synchronous consumer
     *
     * @since 1.0
     */
	virtual void AmqStart() = 0;

	/**
     * Send text data to broker
     * @text 
	 *		to be delivered messages.
     *
     * @since 1.0
     */
	virtual bool AmqSyncReceive( int nDataType, char* data, int nDataSize ) = 0;

};

extern "C"
{
	/**
     * Create one instantce of ActiveMQ consumer
     *  
	 *
     *
     * @since 1.0
     */
	EXPORT_INTERFACE_CLASS IAmqSyncConsumer * AmqCreateSyncCosumer( const char * amqAddress=NULL, const char * cmsQueueName=NULL );
}

/**
* 
* Create Asynchronous consumer
*
*/

class EXPORT_INTERFACE_CLASS IAmqAsyncConsumer
{
public:
	
	virtual ~IAmqAsyncConsumer(){};

	/**
     * Start Asynchronous consumer
     *
     * @since 1.0
     */
	virtual void AmqStart() = 0;

};

class IAmqAsyncConsumerNotify
{
public:
	virtual void OnMessageText( const char* usrid, int type, const char* text )=0;
    virtual void OnMessageStream(const char* stream, CMS_HEADER &header) = 0;
	virtual void OnTransportInterrupted()=0;
	virtual void OnTransportResumed()=0;
};


extern "C"
{
	/**
     * Create one instantce of ActiveMQ Asynchronous consumer
     *  
	 *
     *
     * @since 1.0
     */
    EXPORT_INTERFACE_CLASS IAmqAsyncConsumer* AmqCreateAsyncConsumer(IAmqAsyncConsumerNotify *AsyncConsumerNotify, const char * amqAddress = NULL, 
        const char * cmsQueueOrTopicName = NULL, bool bUseTopic = false);

	EXPORT_INTERFACE_CLASS void AmqDeleteAsyncConsumer( IAmqAsyncConsumer* &AsyncConsumer );
}

#endif
