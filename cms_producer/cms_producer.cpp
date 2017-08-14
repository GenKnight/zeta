#include <iostream>
#include <stdlib.h>
#include <string.h>

#include "fndcms/fndcms.h"
#include <string>
#include "../proto/protocal.pb.h"
#include "../proto/parse.h"
using namespace std;
int main(int argc, char* argv[])
{
    static long start_time = 0;
    static long end_time = 0;

    int msg_counts = 10000;
	char address[32]={0};	//192.168.1.65:61616
    strcpy(address, "127.0.0.1:61616");
	char szQueueOrTopicName[64]="Q.TOM2ERIC";
    IAmqProducer * producer = AmqCreateProducer(address, szQueueOrTopicName);
	producer->AmqStart();

    zeta::login_info msg;
    msg.mutable_head()->set_size(10001);
    msg.mutable_head()->set_type(10002);
    msg.set_userid(10003);
    msg.set_pwd("123456");
    msg.add_record("one");
    msg.add_record("two");
    msg.add_record("three");
    string result;
    encode(result, msg);
    //cout << result.size() << endl;

    CMS_HEADER header;
    header.datasize = result.size();
    header.datatype = 2;
	std::cout << "¿ªÊ¼²âÊÔ" << std::endl;
    {
        SYSTEMTIME st;
        GetLocalTime(&st);
        //nDate = st.wYear * 10000 + st.wMonth * 100 + st.wDay;
        start_time = st.wHour * 10000 * 1000 + st.wMinute * 100 * 1000 + st.wSecond * 1000 + st.wMilliseconds;
    }
    for (int i = 0; i < msg_counts; i++) {
        producer->AmqSendStream(result.c_str(), header);
    }
    {
        SYSTEMTIME st;
        GetLocalTime(&st);
        //nDate = st.wYear * 10000 + st.wMonth * 100 + st.wDay;
        end_time = st.wHour * 10000 * 1000 + st.wMinute * 100 * 1000 + st.wSecond * 1000 + st.wMilliseconds;
        
        std::cout << "start time" << start_time << std::endl;
        std::cout << "end time" << end_time << std::endl;
        std::cout << "diff time" << end_time - start_time << std::endl;
    }
	AmqDeleteProducer( producer );

    getchar();
	return 0;
}

