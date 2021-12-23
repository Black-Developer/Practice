#ifndef __GLTEXTURECOMPONENT_H__
#define __GLTEXTURECOMPONENT_H__

#include "Component.h"
#include "glaux.h"

#pragma warning(disable:4996)

class GLTextureComponent : public Component
{
public:
	GLTextureComponent() {}
	~GLTextureComponent() {}
	int LoadGLTextures(char* szFilePath);
	AUX_RGBImageRec* LoadBMP(char*);
	void Render() override;
private:
	unsigned int MyTextureObject[1];

};


#endif // !__GLTEXTURECOMPONENT_H__
