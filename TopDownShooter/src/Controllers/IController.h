#pragma once

class IController {
public:
	IController() = default;
	virtual ~IController() {}
public:
	virtual void update() = 0;
};