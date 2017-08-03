#ifndef WORKPLAN_TASK_INTERFACE_DEF_H_
#define WORKPLAN_TASK_INTERFACE_DEF_H_

#include <string>
#include <stdio.h>
#include <string.h>
#pragma pack(push,1)     /*指定1字节对齐*/

//错误码定义
#define	PROCESS_SUCCESS				  0	    //处理成功
#define	REQUEST_PACKAGE_ILLEGAL		  1		//请求数据异常
#define	OPERATE_DB_FAILED			  2		//数据库操作失败
#define	USRID_EXISTED				  3		//登录账号已经存在
#define	USRID_NOT_EXISTED			  4		//未注册的手机号
#define	WRONG_PASSWD				  5		//登录密码错误
#define	MAC_ADDRESS_CHANGE			  6		//mac地址变化
#define CMD_NOT_SUPPORTED			  7		//不支持请求
#define	INFO_NOT_EXIST				  8		//无相关信息
#define	NOT_LOGIN_YET				  9		//未登录
#define	ME_ORDER_NOTOVER			 10		//还有融资订单未处理


#define STOCK_SECURITY_TYPE          "1"    //股票
#define FUTURE_SECURITY_TYPE         "2"    //期货


#ifndef _WIN32
typedef unsigned char       BYTE;
#endif

//接口协议定义
//通用数据部分头
typedef struct tagResponseHead
{
	int success;		         //0-成功
	int requestid;		         //类别
	int num;			         //数量
}RESPONSE_HEAD,MULTI_MSGS_HEAD;

//1、注册请求【datatype=1】
typedef struct tagRegister
{
	int num;
}APP_REGISTER;

//2、登录请求【datatype=2】
typedef struct tagLogin
{
	int requestid;	//1--初次登录 2--验证登录 3--前置机登录

	char mobile[16];
	char password[64];
	char remote_ip[16];
	char macAddress[48];

	char reserve[128];		//预留
}APP_LOGIN;

typedef struct tagMemberIdRep
{
	int success;		//0-成功
	int member_id;		//会员id
}APP_MEMBER_ID_REP;

#pragma pack (pop)      /*还原默认字节对齐*/

#endif
