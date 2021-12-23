#ifndef __RENDERCOMPONENT_H__
#define __RENDERCOMPONENT_H__

#include "Component.h"
#include "MolluEngineManager.h"

class RenderComponent : public Component
{
public:
	RenderComponent() { renderer = MolluEngineManager::getInstance().GetRednerer(); }
	virtual ~RenderComponent() = 0 {}
	virtual void Render() {}
	IRenderer* renderer;
};


#endif // !__RENDERCOMPONENT_H__