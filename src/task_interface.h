/******************************************************************************
Copyright (c) 2016. All Rights Reserved.

FileName: task_interface.h
Version: 1.0
Date: 2017.8.5

History:
eric     2017.8.5   1.0     Create
******************************************************************************/

#ifndef __TASK_INTERFACE_H__
#define __TASK_INTERFACE_H__

#include <string>
#include <stdio.h>
#include <string.h>

//�����붨��
const int PROCESS_SUCCESS             = 0;        //����ɹ�
const int REQUEST_PACKAGE_ILLEGAL     = 1;        //���������쳣
const int OPERATE_DB_FAILED           = 2;        //���ݿ����ʧ��

const int STOCK_SECURITY_TYPE         = 1;        //��Ʊ
const int FUTURE_SECURITY_TYPE        = 2;        //�ڻ�

#ifndef _WIN32
typedef unsigned char       BYTE;
#endif

#pragma pack(push,1)     /*ָ��1�ֽڶ���*/
//�ӿ�Э�鶨��
//ͨ�����ݲ���ͷ
typedef struct tagResponseHead
{
	int success;		         //0-�ɹ�
	int requestid;		         //���
	int num;			         //����
}RESPONSE_HEAD,MULTI_MSGS_HEAD;

//1��ע������datatype=1��
typedef struct req_register
{
    char mobile[16];
    char password[32];
}REQ_REGISTER;

typedef struct rsp_register
{
    int success;		//0-�ɹ�
    int member_id;		//��Աid
}RSP_REGISTER;

//1����¼����datatype=2��
typedef struct req_login
{
	int requestid;	//1--���ε�¼ 2--��֤��¼ 3--ǰ�û���¼

	char mobile[16];
	char password[32];
}REQ_LOGIN;

typedef struct rsp_login
{
	int success;		//0-�ɹ�
	int member_id;		//��Աid
}RSP_LOGIN;

#pragma pack (pop)      /*��ԭĬ���ֽڶ���*/

#endif
