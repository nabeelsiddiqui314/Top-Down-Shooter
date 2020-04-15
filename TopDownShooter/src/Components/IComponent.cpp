#include "IComponent.h"
#include "../Entity/Blueprints/IBlueprint.h"
#include "../Entity/EntityManager.h"

IComponent::IComponent(std::weak_ptr<AttributeManager> attributes)
 :  m_attributes(attributes) {}