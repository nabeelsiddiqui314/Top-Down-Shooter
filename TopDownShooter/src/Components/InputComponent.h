#pragma once
#include "IComponent.h"
#include <memory>
#include <unordered_map>
#include <string>

class InputHandler;
class ICommand;

class InputComponent : public IComponent {
private:
	typedef std::unique_ptr<ICommand> CommandPtr;
public:
	InputComponent(std::shared_ptr<InputHandler> inputHandler);
public:
	void bindCommand(const std::string& inputName, CommandPtr&& command);
	void update(float) override;
private:
	std::shared_ptr<InputHandler> m_inputHandler;
	std::unordered_map<std::string, CommandPtr> m_commandMap;
};