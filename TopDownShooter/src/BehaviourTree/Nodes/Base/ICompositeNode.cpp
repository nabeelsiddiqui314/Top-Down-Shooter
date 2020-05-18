#include "ICompositeNode.h"

const std::vector<ICompositeNode::NodePtr>& ICompositeNode::getChildrenNodes() const {
	return m_children;
}
