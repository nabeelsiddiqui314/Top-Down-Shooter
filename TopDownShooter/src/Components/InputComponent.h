#pragma once
#include "IComponent.h"
#include <memory>
#include <unordered_map>
#include <string>

class ICommand;

class InputComponent : public IComponent {
private:
	typedef std::unique_ptr<ICommand> CommandPtr;
public:
	InputComponent() = default;
	~InputComponent() = default;
public:
	void bindCommand(const std::string& inputName, CommandPtr&& command);
	void update(float) override;
private:
	std::unordered_map<std::string, CommandPtr> m_commandMap;
};