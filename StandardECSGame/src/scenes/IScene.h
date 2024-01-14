#pragma once

#include "../../dependencies/entt.hpp"

class IScene {
public:
	virtual void initialiseScene() = 0;
	virtual void destroyScene() = 0;

	virtual void update(float deltaTime) = 0;
	virtual void render(float deltaTime) = 0;

protected:
	const char* _name;
	entt::registry _registry;	
};
