#ifndef __TEXTURECOMPONENT_H__
#define __TEXTURECOMPONENT_H__

#include "Component.h"
#include "MolluEngineManager.h"

class TextureComponent : public Component
{
public:
	TextureComponent() { renderer = MolluEngineManager::getInstance().GetRednerer(); }
	virtual ~TextureComponent() = 0 {}
	virtual void Render() {}
	IRenderer* renderer;
};



#endif // !__TEXTURECOMPONENT_H__
