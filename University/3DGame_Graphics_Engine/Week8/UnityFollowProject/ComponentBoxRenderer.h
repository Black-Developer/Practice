#ifndef __COMPONENTBOXRENDERER_H__
#define __COMPONENTBOXRENDERER_H__

#include "Component.h"

class ComponentBoxRenderer : public Component
{
public:
	ComponentBoxRenderer() {}
	~ComponentBoxRenderer()override {}
	void Start();
	void Update();
	void Render();
	
private:

};
#endif // !_COMPONENTBOXRENDERER_H__
