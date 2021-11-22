#ifndef __MONOBEHAVIOUR_H__
#define __MONOBEHAVIOUR_H__

class monoBehaviour
{
public:
	virtual void Start() = 0;
	virtual void Update() = 0;
	virtual void FixedUpdate() = 0;
	virtual ~monoBehaviour() = 0 {}
};
#endif // !__MONOBEHAVIOUR_H__