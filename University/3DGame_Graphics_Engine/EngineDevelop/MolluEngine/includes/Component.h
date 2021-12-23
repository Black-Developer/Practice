#ifndef __COMPONENT_H__
#define __COMPONENT_H__

class Component
{
public:
	Component(){}
	virtual ~Component() {}
	virtual void Start() {}
	virtual void Update() {}
	virtual void FixedUpdate() {}
	virtual void Render() {}
};


#endif // !__COMPONENT_H__