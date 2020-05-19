#include "Command.h"
#include "RemoteControl.h"
#include "MacroCommand.h"
#include <memory>


int main()
{
	RemoteControl remoteControl;

	auto light = std::make_shared<Light>();
	auto lightOnCommand = std::make_shared<LightOnCommand>(light);
	auto lightOffCommand = std::make_shared<LightOffCommand>(light);

	auto tv = std::make_shared<TV>();
	auto tvOnCommand = std::make_shared<TVOnCommand>(tv);
	auto tvOffCommand = std::make_shared<TVOffCommand>(tv);

	auto fan = std::make_shared<Fan>();
	auto fanOffCommand = std::make_shared<FanOffCommand>(fan);
	auto fanLowCommand = std::make_shared<FanLowCommand>(fan);
	auto fanMediumCommand = std::make_shared<FanMediumCommand>(fan);
	auto fanHighCommand = std::make_shared<FanHighCommand>(fan);

	std::vector<std::shared_ptr<Command>> partyCommandsVector = { lightOnCommand, tvOnCommand, fanHighCommand };
	auto partyCommand = std::make_shared<MacroCommand>(partyCommandsVector);

	remoteControl.setCommand(lightOnCommand);
	remoteControl.press();
	remoteControl.pressUndo();

	remoteControl.setCommand(lightOffCommand);
	remoteControl.press();
	remoteControl.pressUndo();

	remoteControl.setCommand(fanHighCommand);
	remoteControl.press();
	remoteControl.pressUndo();
	remoteControl.pressUndo();
	remoteControl.press();

	remoteControl.setCommand(fanMediumCommand);
	remoteControl.press();
	remoteControl.pressUndo();

	remoteControl.setCommand(partyCommand);
	remoteControl.press();
	remoteControl.pressUndo();
}