#pragma once
#include "Command.h"
#include <memory>

class RemoteControl
{
private:
	std::shared_ptr<Command> command;
public:
	void setCommand(std::shared_ptr<Command> command);
	void press();
	void pressUndo();
};