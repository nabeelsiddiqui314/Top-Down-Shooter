#pragma once
#include "INode.h"
#include <memory>
#include <vector>

class CompositeNode : public INode {
private:
	typedef std::unique_ptr<INode> NodePtr;
public:
	CompositeNode() = default;
	~CompositeNode() = default;
public:
	template <typename T, typename... Args>
	void addChildNode(Args&&... args) {
		m_children.emplace_back(std::make_unique<T>(std::forward<Args>(args)...));
	}
protected:
	const std::vector<NodePtr>& getChildren() const;
private:
	std::vector<NodePtr> m_children;
};