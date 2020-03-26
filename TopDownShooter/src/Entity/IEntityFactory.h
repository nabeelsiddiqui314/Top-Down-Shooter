#pragma once
#include <memory>

class Entity;

class IEntityFactory {
public:
	IEntityFactory() = default;
	~IEntityFactory() = default;
public:
	virtual std::shared_ptr<Entity> createPlayer() const = 0;
};