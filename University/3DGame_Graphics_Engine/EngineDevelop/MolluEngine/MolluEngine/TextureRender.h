#ifndef __TEXTURERENDER_H__
#define __TEXTURERENDER_H__

#include "TextureComponent.h"

class TextureRender : public TextureComponent
{
private:
	TextureRender()
	{
		transform = new Transform();
	}
public:
	TextureRender(const char* _path,GameObject* pOwner, char** _argv)
	{
		transform = pOwner->transform;
		path = _path;
		argv = _argv;
	}
	~TextureRender() { delete transform; }
	void Render() override;
	const char* path;
	char** argv;
	Transform* transform;
};

#endif // !1
