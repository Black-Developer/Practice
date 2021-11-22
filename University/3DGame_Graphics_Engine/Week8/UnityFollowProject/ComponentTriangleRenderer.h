#ifndef __COMPONENTTRIANGLERENDERER_H__
#define __COMPONENTTRIANGLERENDERER_H__

#include "Component.h"

class ComponentTriangleRenderer : public Component
{
public:
	ComponentTriangleRenderer() {}
	~ComponentTriangleRenderer()override {}
	void Start();
	void Update();
	void Render();
	void FixedUpdate();
private:

};
#endif // !__COMPONENTTRIANGLERENDERER_H__
