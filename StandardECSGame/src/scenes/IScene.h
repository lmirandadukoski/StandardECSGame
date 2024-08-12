#pragma once

#include "../../dependencies/entt.hpp"

class IScene {
public:
	virtual void load() = 0;
	virtual void update(float deltaTime) = 0;
	virtual void render(float deltaTime) = 0;
	virtual void destroy() = 0;

protected:
	const char* _name;
	entt::registry _registry;	
};
