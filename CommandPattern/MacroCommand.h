#pragma once
#include "Command.h"
#include <vector>

class MacroCommand : public Command
{
private:
	std::vector<std::shared_ptr<Command>>& commands;
public:
	MacroCommand() = delete;
	MacroCommand(std::vector<std::shared_ptr<Command>>& commands);
	virtual void execute() override;
	virtual void undo() override;
};