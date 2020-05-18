#include "Command.h"
#include <iostream>

LightOnCommand::LightOnCommand(Light* light) : light(light) {}

void LightOnCommand::execute()
{
	light->on();
}

void LightOnCommand::undo()
{
	light->off();
}

LightOffCommand::LightOffCommand(Light* light) : light(light) {}

void LightOffCommand::execute()
{
	light->off();
}

void LightOffCommand::undo()
{
	light->on();
}

TVOnCommand::TVOnCommand(TV* tv) : tv(tv) {}

void TVOnCommand::execute()
{
	tv->on();
}

void TVOnCommand::undo()
{
	tv->off();
}

TVOffCommand::TVOffCommand(TV* tv) : tv(tv) {}

void TVOffCommand::execute()
{
	tv->off();
}

void TVOffCommand::undo()
{
	tv->on();
}

FanCommand::FanCommand(Fan* fan) : fan(fan) {}

void FanCommand::undo()
{
	switch (prevSpeed)
	{
	case 0:
		fan->off();
		break;
	case 1:
		fan->low();
		break;
	case 2:
		fan->medium();
		break;
	case 3:
		fan->high();
		break;
	default:
		break;
	}
}

void FanCommand::execute()
{
	prevSpeed = fan->getSpeed();
}

FanHighCommand::FanHighCommand(Fan* fan) : FanCommand(fan) {}

void FanHighCommand::execute()
{
	FanCommand::execute();
	fan->high();
}

FanMediumCommand::FanMediumCommand(Fan* fan) : FanCommand(fan) {}

void FanMediumCommand::execute()
{
	FanCommand::execute();
	fan->high();
}

FanLowCommand::FanLowCommand(Fan* fan) : FanCommand(fan) {}

void FanLowCommand::execute()
{
	FanCommand::execute();
	fan->high();
}

FanOffCommand::FanOffCommand(Fan* fan) : FanCommand(fan) {}

void FanOffCommand::execute()
{
	FanCommand::execute();
	fan->high();
}