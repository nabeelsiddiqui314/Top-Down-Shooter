#include "CompositeNode.h"

const std::vector<CompositeNode::NodePtr>& CompositeNode::getChildren() const {
	return m_children;
}
