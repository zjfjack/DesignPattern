#include "RemoteControl.h"

void RemoteControl::setCommand(std::shared_ptr<Command> command)
{
	this->command = command;
}

void RemoteControl::press()
{
	if (command)
		command->execute();
}

void RemoteControl::pressUndo()
{
	if (command)
		command->undo();
}