#include "IComponent.h"

IComponent::IComponent(std::weak_ptr<AttributeManager> attributes)
 :  m_attributes(attributes) {}