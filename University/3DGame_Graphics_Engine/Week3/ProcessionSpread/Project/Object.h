#ifndef __OBJECT_H__
#define __OBJECT_H__

#include "Component.h"
#include "Vector3.h"
#include <string>
#include <vector>

using std::vector;
using std::string;

class Object : public Component
{
public:
	Object();
	Object(string id);
	Object(string id, Vector3 position);
	~Object();
	void setPosition(Vector3);
	void setPosition(int, int, int);

	void translate(int, int, int);
	void translate(Vector3);

	void addChild(Object* obj);
	void list() const;
protected:
	Vector3 position_;
private:
	vector<Object*>* table_;
	string id_;
};

#endif