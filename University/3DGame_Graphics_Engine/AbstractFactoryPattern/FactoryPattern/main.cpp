#include <iostream>

using namespace std;


class Factory
{
public:
	Factory();
	~Factory();

private:

};

Factory::Factory()
{
}

Factory::~Factory()
{
}

class NormalFactory : public Factory
{
public:
	NormalFactory();
	~NormalFactory();

private:

};

NormalFactory::NormalFactory()
{
}

NormalFactory::~NormalFactory()
{
}
class RareFactory : public Factory
{
public:
	RareFactory();
	~RareFactory();

private:

};

RareFactory::RareFactory()
{
}

RareFactory::~RareFactory()
{
}

void main()
{
	Factory* nf = new NormalFactory;

}

