#pragma once
#include <memory>
#include "IComponent.h"

class Camera;
class TransformAttribute;

class CameraComponent : public IComponent {
public:
	CameraComponent(std::shared_ptr<Camera> camera);
	~CameraComponent() = default;
public:
	void fetchAttributes(std::shared_ptr<AttributeManager> attributes) override;
	void update(float) override;
private:
	std::shared_ptr<Camera> m_camera;
	std::shared_ptr<TransformAttribute> m_transformAttribute;
};