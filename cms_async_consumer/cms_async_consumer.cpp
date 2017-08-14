#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <memory>
#include "fndcms/fndcms.h"
#include <string>
#include "../proto/protocal.pb.h"
#include "../proto/parse.h"
using namespace std;

class AsyncConsumerReceiver
    : public IAmqAsyncConsumerNotify
{
public:
	AsyncConsumerReceiver(){};
	~AsyncConsumerReceiver(){};

public:
	virtual void OnMessageText( const char* usrid, int type, const char* text )
	{
#ifdef _DEBUG
		static int n=1;
		printf( "Recv msg[%d] from usr [ %s ]:%s\n", n++, usrid, text );
#endif
	}

	virtual void OnMessageStream( const char* stream, CMS_HEADER &header  )
	{
        static long start_time = 0;
        static long end_time = 0;

		static int n=0;
		if (n == 0)
		{
			SYSTEMTIME st;
			GetLocalTime(&st);
			//nDate = st.wYear * 10000 + st.wMonth * 100 + st.wDay;
			start_time = st.wHour * 10000 * 1000 + st.wMinute * 100 * 1000 + st.wSecond * 1000 + st.wMilliseconds;
		}
        try
        {
            //int32_t len = asInt32((const char*)stream);
            //string read_msg;
            //read_msg.resize(len);
            //memcpy(&read_msg[0],
            //    (const char*)stream + sizeof(int32_t),
            //    len);
            //std::shared_ptr<google::protobuf::Message>
            //    msg_ptr(decode(read_msg));

            //google::protobuf::Message* pMsg = msg_ptr.get();
            //if (pMsg && pMsg->GetDescriptor() == zeta::login_info::descriptor()) {
            //    zeta::login_info* pReq = dynamic_cast<zeta::login_info*>(pMsg);
            //    cout << pReq->mutable_head()->size() << endl;
            //    cout << pReq->userid() << endl;
            //    cout << pReq->pwd() << endl;
            //    for (int i = 0; i < pReq->record_size(); i++) {
            //        cout << pReq->record(i) << endl;
            //    }
            //}
        }
        catch (...)
        {
            return;
        }

        n++;
        if (n == 10000)
        {
            SYSTEMTIME st;
            GetLocalTime(&st);
            //nDate = st.wYear * 10000 + st.wMonth * 100 + st.wDay;
            end_time = st.wHour * 10000 * 1000 + st.wMinute * 100 * 1000 + st.wSecond * 1000 + st.wMilliseconds;

            std::cout << "start time" << start_time << std::endl;
            std::cout << "end time" << end_time << std::endl;
            std::cout << "diff time" << end_time - start_time << std::endl;
        }
	}

	virtual void OnTransportInterrupted()
	{
	}
	virtual void OnTransportResumed()
	{

	}
};

int main(int argc, char* argv[])
{
	bool bUseTopic=false;
	char szAddress[32]={0};	//192.168.1.65:61616
	strcpy( szAddress, "127.0.0.1:61616" );
	char szQueueOrTopicName[64]="Q.TOM2ERIC";

	AsyncConsumerReceiver acr;
	IAmqAsyncConsumer * consumer = AmqCreateAsyncConsumer( &acr, szAddress, szQueueOrTopicName );
	consumer->AmqStart();

    getchar();

	AmqDeleteAsyncConsumer( consumer );

	return 0;
}

