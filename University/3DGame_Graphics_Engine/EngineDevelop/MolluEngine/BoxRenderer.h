#ifndef __BOXRENDERER_H__
#define __BOXREDNERER_H__

#include "Component.h"
#include "Transform.h"
#include "GameObject.h"

class BoxRenderer : public Component
{
public:
	BoxRenderer() {}
	virtual ~BoxRenderer() {}
	virtual void Render() {}
};

class GL_BoxRenderer : public BoxRenderer
{
public:
	GL_BoxRenderer(GameObject* parent) : transform(parent->transform) {}
	~GL_BoxRenderer() {}
	void Render() override;
private:
	Transform transform;
};

class DX_BoxRenderer : public BoxRenderer
{
public :
	DX_BoxRenderer(Transform _transform) : transform(_transform) {}
	~DX_BoxRenderer() {}
	void Render() override;
private:
	Transform transform;
};


#endif // !__BOXRENDERER_H__
