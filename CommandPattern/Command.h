#pragma once
#include "Light.h"
#include "TV.h"
#include "Fan.h"
#include <memory>

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
	std::shared_ptr<Light> light;
public:
	LightOnCommand(std::shared_ptr<Light> light);
	virtual void execute() override;
	virtual void undo() override;
};

class LightOffCommand : public Command
{
private:
	std::shared_ptr<Light> light;
public:
	LightOffCommand(std::shared_ptr<Light> light);
	virtual void execute() override;
	virtual void undo() override;
};

class TVOnCommand : public Command
{
private:
	std::shared_ptr<TV> tv;
public:
	TVOnCommand(std::shared_ptr<TV> tv);
	virtual void execute() override;
	virtual void undo() override;
};

class TVOffCommand : public Command
{
private:
	std::shared_ptr<TV> tv;
public:
	TVOffCommand(std::shared_ptr<TV> tv);
	virtual void execute() override;
	virtual void undo() override;
};

class FanCommand : public Command
{
public:
	virtual void undo() override;
	virtual void execute() override;
protected:
	FanCommand(std::shared_ptr<Fan> fan);
	std::shared_ptr<Fan> fan = nullptr;
	int prevSpeed = 0;
};

class FanHighCommand : public FanCommand
{
public:
	FanHighCommand(std::shared_ptr<Fan> fan);
	virtual void execute() override;
};

class FanMediumCommand : public FanCommand
{
public:
	FanMediumCommand(std::shared_ptr<Fan> fan);
	virtual void execute() override;
};

class FanLowCommand : public FanCommand
{
public:
	FanLowCommand(std::shared_ptr<Fan> fan);
	virtual void execute() override;
};

class FanOffCommand : public FanCommand
{
public:
	FanOffCommand(std::shared_ptr<Fan> fan);
	virtual void execute() override;
};