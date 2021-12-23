#ifndef __DXOBJLOADER_H__
#define __DXOBJLOADER_H__

#include "OBJLoader.h"

class DXOBJLoader : public ObjLoader
{
public:
	DXOBJLoader()
	{
	}

	~DXOBJLoader()
	{
	}
	bool LoadOBJ(const char* path) override;
private:

};



#endif // !__DXOBJLOADER_H__
