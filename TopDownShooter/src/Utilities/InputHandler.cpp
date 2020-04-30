#include "InputHandler.h"

InputHandler& InputHandler::getInstance() {
	static InputHandler instance;
	return instance;
}

void InputHandler::bind(const std::string& inputName, const sf::Keyboard::Key& key) {
	bindNameToCallback(inputName, [key]() {
		return sf::Keyboard::isKeyPressed(key);
	});
}

void InputHandler::bind(const std::string& inputName, const sf::Mouse::Button& button) {
	bindNameToCallback(inputName, [button]() {
		return sf::Mouse::isButtonPressed(button);
	});
}

bool InputHandler::isButtonDown(const std::string& inputName) const {
	if (doesInputExist(inputName)) {
		return m_inputMap.at(inputName)();
	}
	return false;
}

void InputHandler::bindNameToCallback(const std::string& inputName, const InputQueryCallback& callback) {
	if (!doesInputExist(inputName)) {
		m_inputMap.emplace(std::make_pair(inputName, callback));
	}
}

bool InputHandler::doesInputExist(const std::string& inputName) const {
	return m_inputMap.find(inputName) != m_inputMap.end();
}
