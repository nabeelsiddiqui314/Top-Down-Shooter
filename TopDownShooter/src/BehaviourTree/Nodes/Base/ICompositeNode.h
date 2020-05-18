#pragma once
#include "INode.h"
#include <memory>
#include <vector>

class ICompositeNode : public INode {
private:
	typedef std::unique_ptr<INode> NodePtr;
public:
	ICompositeNode() = default;
	~ICompositeNode() = default;
public:
	template <typename T, typename... Args>
	std::unique_ptr<T>& addChildNode(Args&&... args) {
		m_children.emplace_back(std::make_unique<T>(std::forward<Args>(args)...));
	}
protected:
	const std::vector<NodePtr>& getChildrenNodes() const;
private:
	std::vector<NodePtr> m_children;
};