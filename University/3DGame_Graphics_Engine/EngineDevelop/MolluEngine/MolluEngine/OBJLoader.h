#ifndef __OBJLOADER_H__
#define __OBJLOADER_H__

__interface ObjLoader
{
public:
	virtual bool LoadOBJ(const char* path) = 0;
};

#endif // !__OBJLOADER_H__
