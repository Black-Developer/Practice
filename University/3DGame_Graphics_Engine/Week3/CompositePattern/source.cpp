#include <iostream>
#include <vector>
#include <string>

using std::cout;
using std::vector;
using std::string;
using std::endl;

class Component
{
public:
	virtual void list() const = 0;
	virtual ~Component() {};
};

class Leaf : public Component
{
public:
	Leaf(int val) : value_(val)
	{
	}
	
	void list() const
	{
		cout << " " << value_ << endl;
	}
private:
	int value_;
};

class Composite : public Component
{
public:
	Composite(string id) : id_(id)
	{
		table_ = new vector<Component*>();
	}
	~Composite()
	{
		for (vector<Component*>::const_iterator it = table_->begin(); it != table_->end(); ++it)
		{
			delete(*it);
		}
	}


	void add(Component *obj)
	{
		table_->push_back(obj);
	}

	void list() const
	{
		cout << id_ << ":" << endl;

		for (vector<Component*>::const_iterator it = table_->begin(); it != table_->end(); ++it)
		{
			(*it)->list();
		}
	}

private:
	vector<Component*>* table_;
	string id_;
};

int main()
{
	Leaf* num0 = new Leaf(0);
	Leaf* num1 = new Leaf(1);
	Leaf* num2 = new Leaf(2);
	Leaf* num3 = new Leaf(3);
	Leaf* num4 = new Leaf(4);

	Composite* container1 = new Composite("Container 1");
	Composite* container2 = new Composite("Container 2");

	container1->add(num0);
	container1->add(num1);

	container2->add(num2);
	container2->add(num3);
	container2->add(num4);

	container1->add(container2);
	container1->list();

	delete container1;

	return 0;
}