#include "TaskLogin.h"
#include "TaskInterfaceDef.h"
#include <memory>
#include "proto/parse.h"
#include "proto/protocal.pb.h"
#include <iostream>
namespace itstation 
{

	CTaskLogin::CTaskLogin( TaskData task_desc)
        :EngineTask(task_desc)
	{
		
	}

	CTaskLogin::~CTaskLogin(void)
	{
	}

	//@brief    : execute implement method, implement task execute operator
	//@return   : return 0 if success, or -1 if failed
	int CTaskLogin::executeImpl()
	{
		ASSET_MESSAGE_STRUCT Msg;
		TCP_MSG_HEAD header;

		task_desc_.get_task_message( Msg );

		header.datatype = Msg.header.datatype;
		header.datasize = sizeof(int);
        int32_t len = asInt32((const char*)Msg.ptrData);
        string read_msg;
        read_msg.resize(len);
        memcpy(&read_msg[0], 
            (const char*)Msg.ptrData+sizeof(int32_t),
            len);
        //read_msg.append((const char *)Msg.ptrData + sizeof(int32_t));
		try
		{
            std::shared_ptr<google::protobuf::Message> 
                msg_ptr(decode(read_msg));

            google::protobuf::Message* pMsg = msg_ptr.get();
            if (pMsg && pMsg->GetDescriptor() == zeta::login_info::descriptor()) {
                zeta::login_info* pReq = dynamic_cast<zeta::login_info*>(pMsg);
                cout << pReq->mutable_head()->size() << endl;
                cout << pReq->userid() << endl;
                cout << pReq->pwd() << endl;
            }
		}
		catch( ... )
		{
			return -1;
		}

		return 0;
	}
} //namespace itstation 