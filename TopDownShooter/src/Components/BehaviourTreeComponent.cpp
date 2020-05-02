#include "BehaviourTreeComponent.h"
#include "../AI/Nodes/Base/INode.h"

BehaviourTreeComponent::BehaviourTreeComponent(NodePtr root) 
	: m_rootNode(root) {}

void BehaviourTreeComponent::update(float) {
	m_rootNode->process();
}