#pragma once
#include "INode.h"
#include <memory>

class IDecoratorNode : public INode {
private:
	typedef std::unique_ptr<INode> NodePtr;
public:
	IDecoratorNode() = default;
	~IDecoratorNode() = default;
public:
	template <typename T, typename... Args>
	std::unique_ptr<T>& setChildNode(Args&&... args) {
		m_child = std::make_unique<T>(std::forward<Args>(args)...);
	}
private:
	NodePtr m_child;
};