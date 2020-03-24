#pragma once
#include <string>
#include <memory>
#include <unordered_map>

template <typename T> // Shared resource management
class ResourceContainer {
public:
	ResourceContainer(const std::string& folderPath) 
	 : m_folderPath(folderPath) {};

	~ResourceContainer() = default;
public:
	std::shared_ptr<T> aquire(const std::string& name) {
		if (m_resources.find(name) == m_resources.end()) {
			auto resource = std::make_shared<T>();
			resource->loadFromFile(m_folderPath + name);

			m_resources.insert(std::make_pair(name, resource));

			return resource;
		}

		return m_resources.at(name);
	}

	void freeOrphanResources() {
		for (auto iter = m_resources.begin(); iter != m_resources.end();) {
			if (iter->second.unique()) {
				iter = m_resources.erase(iter);
			}
			else {
				iter++;
			}
		}
	}

private:
	std::unordered_map<std::string, std::shared_ptr<T>> m_resources;
	std::string m_folderPath;
};