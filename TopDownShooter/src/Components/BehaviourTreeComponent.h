#pragma once
#include "IComponent.h"

class INode;

class BehaviourTreeComponent : public IComponent {
private:
	typedef std::shared_ptr<INode> NodePtr;
public:
	BehaviourTreeComponent(NodePtr root);
	~BehaviourTreeComponent() = default;
public:
	void update(float) override;
private:
	 NodePtr m_rootNode;
};