#include "Mesh.h"
#include "DXOBJLoader.h"
#include "OpenGLOBJLoader.h"

#include <iostream>
void Mesh::Render()
{
	try
	{
		if (loader == nullptr)
		{
			throw "Loader IS Null";
		}
	}
	catch (const char* error)
	{
		std::cout << error << std::endl;
	}
	loader->LoadOBJ(fileName);
}

ObjLoader* Mesh::SetLoader(ERenderer ERENDERER)
{

	switch (ERENDERER)
	{
	case isValid:
		break;
	case E_OPENGL:
		loader = new OpenGLOBJLoader();
		return loader;
		break;
	case E_DIRECTX:
		loader = new DXOBJLoader();
		return loader;
		break;
	default:
		break;
	}
	return nullptr;
}
