#pragma once

enum class Status {
	SUCCESS,
	FALIURE,
	RUNNING
};

class INode {
public:
	INode() = default;
	virtual ~INode() {}
public:
	virtual Status process() = 0;
};