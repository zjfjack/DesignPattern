#pragma once
#include "Light.h"
#include "TV.h"
#include "Fan.h"

class Command
{
public:
	virtual ~Command() = default;
	virtual void execute() = 0;
	virtual void undo() = 0;
};

class LightOnCommand : public Command
{
private:
	Light* light = nullptr;
public:
	LightOnCommand(Light* light);
	virtual void execute() override;
	virtual void undo() override;
};

class LightOffCommand : public Command
{
private:
	Light* light = nullptr;
public:
	LightOffCommand(Light* light);
	virtual void execute() override;
	virtual void undo() override;
};

class TVOnCommand : public Command
{
private:
	TV* tv = nullptr;
public:
	TVOnCommand(TV* tv);
	virtual void execute() override;
	virtual void undo() override;
};

class TVOffCommand : public Command
{
private:
	TV* tv = nullptr;
public:
	TVOffCommand(TV* tv);
	virtual void execute() override;
	virtual void undo() override;
};

class FanCommand : public Command
{
public:
	virtual void undo() override;
	virtual void execute() override;
protected:
	FanCommand(Fan* fan);
	Fan* fan = nullptr;
	int prevSpeed = 0;
};

class FanHighCommand : public FanCommand
{
public:
	FanHighCommand(Fan* fan);
	virtual void execute() override;
};

class FanMediumCommand : public FanCommand
{
public:
	FanMediumCommand(Fan* fan);
	virtual void execute() override;
};

class FanLowCommand : public FanCommand
{
public:
	FanLowCommand(Fan* fan);
	virtual void execute() override;
};

class FanOffCommand : public FanCommand
{
public:
	FanOffCommand(Fan* fan);
	virtual void execute() override;
};