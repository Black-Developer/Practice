#include "TextureRender.h"

void TextureRender::Render()
{
	renderer->StartRender();
	renderer->StartTextureRender(path,argv);
	renderer->LoadTexture();
	renderer->EndTextureRender();
	renderer->EndRender();
}

