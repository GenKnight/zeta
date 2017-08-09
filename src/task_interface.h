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

//错误码定义
const int PROCESS_SUCCESS             = 0;        //处理成功
const int REQUEST_PACKAGE_ILLEGAL     = 1;        //请求数据异常
const int OPERATE_DB_FAILED           = 2;        //数据库操作失败

const int STOCK_SECURITY_TYPE         = 1;        //股票
const int FUTURE_SECURITY_TYPE        = 2;        //期货

#ifndef _WIN32
typedef unsigned char       BYTE;
#endif

#pragma pack(push,1)     /*指定1字节对齐*/
//接口协议定义
//通用数据部分头
typedef struct tagResponseHead
{
	int success;		         //0-成功
	int requestid;		         //类别
	int num;			         //数量
}RESPONSE_HEAD,MULTI_MSGS_HEAD;

//1、注册请求【datatype=1】
typedef struct req_register
{
    char mobile[16];
    char password[32];
}REQ_REGISTER;

typedef struct rsp_register
{
    int success;		//0-成功
    int member_id;		//会员id
}RSP_REGISTER;

//1、登录请求【datatype=2】
typedef struct req_login
{
	int requestid;	//1--初次登录 2--验证登录 3--前置机登录

	char mobile[16];
	char password[32];
}REQ_LOGIN;

typedef struct rsp_login
{
	int success;		//0-成功
	int member_id;		//会员id
}RSP_LOGIN;

#pragma pack (pop)      /*还原默认字节对齐*/

#endif
