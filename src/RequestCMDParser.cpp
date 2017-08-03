#include <memory>
#include "RequestCMDParser.h"
#include "TaskFactory.h"
#include "EngineTask.h"
namespace itstation 
{
	RequestCMDParser::RequestCMDParser() 
	{
	}
	RequestCMDParser::~RequestCMDParser() 
	{
	}


	int RequestCMDParser::parseTaskGroup(ASSET_MESSAGE_STRUCT Message, RequestCommand& cmd) 
	{
		std::shared_ptr<EngineTask> task( get_TaskFactory().createEngineTask(Message));
		if(task == nullptr) {
			throw "unknown task id";
		}			

		cmd.tasks_[Message.header.datatype] = task;

		return 0;
	}
} // namespace itstation
