#include "InputComponent.h"
#include "../Utilities/InputHandler.h"
#include "../Commands/ICommand.h"

void InputComponent::bindCommand(const std::string& inputName, CommandPtr&& command) {
	if (m_commandMap.find(inputName) == m_commandMap.end()) {
		m_commandMap.emplace(std::make_pair(inputName, std::move(command)));
	}
}

void InputComponent::update(float) {
	for (auto& commandPair : m_commandMap) {
		auto& inputName = commandPair.first;
		auto& command = commandPair.second;

		auto& inputHandler = InputHandler::getInstance();

		if (inputHandler.isButtonDown(inputName)) {
			command->execute();
		}
	}
}