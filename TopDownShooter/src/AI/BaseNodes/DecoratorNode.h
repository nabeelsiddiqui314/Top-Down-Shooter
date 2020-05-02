#pragma once
#include "INode.h"
#include <memory>

class DecoratorNode : public INode {
private:
	typedef std::unique_ptr<INode> NodePtr;
public:
	DecoratorNode() = default;
	~DecoratorNode() = default;
public:
	template <typename T, typename... Args>
	void setChildNode(Args&&... args) {
		m_child = std::make_unique<T>(std::forward<Args>(args)...);
	}
private:
	NodePtr m_child;
};