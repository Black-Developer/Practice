#ifndef __BOXRENDER_H__
#define __BOXREDNER_H__

#include "RenderComponent.h"
#include "Transform.h"
#include "GameObject.h"

class BoxRender : public RenderComponent
{
private:
	BoxRender() { transform = new Transform(); }
public:
	BoxRender(GameObject* pOwner) { transform = pOwner->transform; }
	~BoxRender() {}
	void Render() override;
	Transform* transform;
};

#endif // !__BOXRENDER_H__
