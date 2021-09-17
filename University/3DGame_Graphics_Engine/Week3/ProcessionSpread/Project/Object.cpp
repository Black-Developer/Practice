#include <iostream>
#include "Object.h"

using namespace std;

Object::Object()
{
	table_ = new vector<Object*>();
}


Object::Object(string id, Vector3 position) : id_(id), position_(position)
{
	id_ = id;
	position_ = position;
table_ = new vector<Object*>();
}

Object::Object(string id) : id_(id), position_(0, 0, 0)
{
	id_ = id;
	position_.x_ = 0;
	position_.y_ = 0;
	position_.z_ = 0;
	table_ = new vector<Object*>();
}

Object::~Object()
{
	for (vector<Object*>::const_iterator it = table_->begin(); it != table_->end(); it++)
	{
		delete(*it);
	}
	table_->clear();

	delete table_;
}

// 위치를 직접적으로 설정하기 위한 함수
void Object::setPosition(Vector3 newPosition)
{
	position_ = newPosition;
}
void Object::setPosition(int x, int y, int z)
{
	position_.x_ = x;
	position_.y_ = y;
	position_.z_ = z;
}

void Object::translate(int x, int y, int z)
{
	position_.x_ += x;
	position_.y_ += y;
	position_.z_ += z;

	for (vector<Object*>::const_iterator it = table_->begin(); it != table_->end(); ++it)
	{
		(*it)->translate(x,y,z);
	}
}

void Object::translate(Vector3 newPosition)
{
	position_ += newPosition;

	for (vector<Object*>::const_iterator it = table_->begin(); it != table_->end(); ++it)
	{
		(*it)->translate(newPosition);

	}
}



// Object를 출력
void Object::list()const
{
	cout << id_ << "\t: position -> " << "x : " << position_.x_ << ", " << "y : " << position_.y_ << ", " << "z :" << position_.z_ << endl;

	for (vector<Object*>::const_iterator it = table_->begin(); it != table_->end(); ++it)
	{
		(*it)->list();
	}
}


void Object::addChild(Object* obj)
{
	table_->push_back(obj);
}