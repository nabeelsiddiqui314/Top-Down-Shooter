#pragma once
#include <memory>
#include <vector>
#include <type_traits>
#include <unordered_map>
#include <cassert>

class IAttribute;

class AttributeManager {
	typedef std::shared_ptr<IAttribute> AttributePtr;
	typedef std::size_t AttributeID;
public:
	AttributeManager() = default;
	~AttributeManager() = default;
public:
	template <typename T, typename... Args>
	std::weak_ptr<T> addAttribue(Args&&... args) {
		auto attributeID = getAttributeID<T>();

		assert(!hasAttribute<T>(), "Trying to add an existing attribute!");

		auto attribute = std::make_shared<T>(std::forward<Args>(args)...);
		m_attributeIndexMap.emplace(std::make_pair(attributeID, m_attributes.size()));
		m_attributes.push_back(attribute);

		return std::static_pointer_cast<T>(m_attributes.back());
	}

	template <typename T>
	bool hasAttribute() {
		auto attributeID = getAttributeID<T>();
		return m_attributeIndexMap.find(attributeID) != m_attributeIndexMap.end();
	}

	template <typename T>
	std::weak_ptr<T> getAttribute() {
		auto attributeID = getAttributeID<T>();
		assert(hasAttribute<T>(), "Trying to fetch invalid attribute");
		return std::static_pointer_cast<T>(m_attributes[m_attributeIndexMap.at(attributeID)]);
	}
private:
	AttributeID generateAttributeID() {
		static AttributeID ID{ 0 };
		return ID++;
	}

	template <typename T>
	AttributeID getAttributeID() {
		static_assert(std::is_base_of<IAttribute, T>::value, "Invalid attribute type!");
		static AttributeID ID{ generateAttributeID() };
		return ID;
	}
private:
	std::vector<AttributePtr> m_attributes;
	std::unordered_map<AttributeID, std::size_t> m_attributeIndexMap;
};