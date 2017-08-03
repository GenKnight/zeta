#ifndef WORKPLAN_TASK_LOGIN_H_
#define WORKPLAN_TASK_LOGIN_H_

#include "EngineTask.h"

namespace itstation 
{
	class CTaskLogin :
		public EngineTask
	{
	public:
		CTaskLogin(void){};
		explicit CTaskLogin( TaskData task_desc);

		virtual ~CTaskLogin(void);

		//@brief    : execute implement method, implement task execute operator
		//@return   : return 0 if success, or -1 if failed
		virtual int executeImpl();
	};

} //namespace itstation 
#endif

