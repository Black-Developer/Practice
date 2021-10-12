#ifndef __OBJECT_H__
#define __OBJECT_H__

#include <string>

class Object
{
public:
	Object(std::string name) : m_Name(name), i(0),j(0) {}
	Object() :i(0),j(0){}
	~Object() {}
	virtual void Update();
	virtual void FixedUpdate();
	std::string m_Name;
	// i for check Update
	int i;
	// j for check FixedUpdate
	int j;
};

#endif // !__OBJECT_H__
