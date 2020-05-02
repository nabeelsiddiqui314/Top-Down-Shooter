#include "CompositeNode.h"

const std::vector<CompositeNode::NodePtr>& CompositeNode::getChildrenNodes() const {
	return m_children;
}
