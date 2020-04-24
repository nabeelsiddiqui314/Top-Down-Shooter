#pragma once
#include <string>
#include <unordered_map>
#include <functional>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/Mouse.hpp>

class InputHandler {
private:
	typedef std::function<bool()> InputQueryCallback;
public:
	InputHandler() = default;
	~InputHandler() = default;
public:
	void bind(const std::string& inputName, const sf::Keyboard::Key& key);
	void bind(const std::string& inputName, const sf::Mouse::Button& button);

	bool isButtonDown(const std::string& inputName) const;
private:
	void bindNameToCallback(const std::string& inputName, const InputQueryCallback& callback);
	bool doesInputExist(const std::string& inputName) const;
private:
	std::unordered_map<std::string, InputQueryCallback> m_inputMap;
};