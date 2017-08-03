#ifndef WORKPLAN_TASK_INTERFACE_DEF_H_
#define WORKPLAN_TASK_INTERFACE_DEF_H_

#include <string>
#include <stdio.h>
#include <string.h>
#pragma pack(push,1)     /*ָ��1�ֽڶ���*/

//�����붨��
#define	PROCESS_SUCCESS				  0	    //����ɹ�
#define	REQUEST_PACKAGE_ILLEGAL		  1		//���������쳣
#define	OPERATE_DB_FAILED			  2		//���ݿ����ʧ��
#define	USRID_EXISTED				  3		//��¼�˺��Ѿ�����
#define	USRID_NOT_EXISTED			  4		//δע����ֻ���
#define	WRONG_PASSWD				  5		//��¼�������
#define	MAC_ADDRESS_CHANGE			  6		//mac��ַ�仯
#define CMD_NOT_SUPPORTED			  7		//��֧������
#define	INFO_NOT_EXIST				  8		//�������Ϣ
#define	NOT_LOGIN_YET				  9		//δ��¼
#define	ME_ORDER_NOTOVER			 10		//�������ʶ���δ����


#define STOCK_SECURITY_TYPE          "1"    //��Ʊ
#define FUTURE_SECURITY_TYPE         "2"    //�ڻ�


#ifndef _WIN32
typedef unsigned char       BYTE;
#endif

//�ӿ�Э�鶨��
//ͨ�����ݲ���ͷ
typedef struct tagResponseHead
{
	int success;		         //0-�ɹ�
	int requestid;		         //���
	int num;			         //����
}RESPONSE_HEAD,MULTI_MSGS_HEAD;

//1��ע������datatype=1��
typedef struct tagRegister
{
	int num;
}APP_REGISTER;

//2����¼����datatype=2��
typedef struct tagLogin
{
	int requestid;	//1--���ε�¼ 2--��֤��¼ 3--ǰ�û���¼

	char mobile[16];
	char password[64];
	char remote_ip[16];
	char macAddress[48];

	char reserve[128];		//Ԥ��
}APP_LOGIN;

typedef struct tagMemberIdRep
{
	int success;		//0-�ɹ�
	int member_id;		//��Աid
}APP_MEMBER_ID_REP;

#pragma pack (pop)      /*��ԭĬ���ֽڶ���*/

#endif
