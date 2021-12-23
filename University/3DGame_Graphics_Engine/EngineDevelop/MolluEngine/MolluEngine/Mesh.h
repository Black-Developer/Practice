#ifndef __MESH_H__
#define __MESH_H__

#include "Component.h"
#include "OBJLoader.h"

enum ERenderer
{
	isValid = 0,
	E_OPENGL = 1,
	E_DIRECTX = 2
};

class Mesh : public Component
{
public:
	Mesh() : fileName(nullptr){}
	Mesh(const char* _fileName) : fileName(_fileName){}
	~Mesh() {}
	
	void Render() override;
	ObjLoader* SetLoader(ERenderer);

private:
	ObjLoader* loader;
	const char* fileName;
};

#endif // __MESH_H__
