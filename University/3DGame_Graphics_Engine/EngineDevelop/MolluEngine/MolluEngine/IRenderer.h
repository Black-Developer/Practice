#ifndef __IRENDERER_H__
#define __IRENDERER_H__

__interface IRenderer
{
public:
	//	virtual void Init(int argc, char** argv) = 0;
	virtual void Init(int argc, char**, int, int) = 0;
	virtual void InitCamera() = 0;
	virtual void Loop() = 0;
	virtual void Terminate() = 0;
	virtual void Vertex2f(float, float) = 0;
	virtual void StartRender() = 0;
	virtual void EndRender() = 0;
	virtual int StartTextureRender(const char*, char**) = 0;
	virtual void EndTextureRender() = 0;
	virtual void LoadTexture() = 0;

};

#endif // !__IRENDERER_H__
