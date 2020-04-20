#pragma once

class ICommand {
public:
	ICommand() = default;
	virtual ~ICommand() {};
public:
	virtual void execute() = 0;
};