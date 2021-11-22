#ifndef __IRENDERER_H__
#define __IRENDERER_H__

__interface IRenderer
{
public:
	virtual void Init(int argc, char** argv) = 0;
	virtual void InitCamera() = 0;
	virtual void Loop() = 0;
	virtual void Terminate() = 0;
};

#endif // !__IRENDERER_H__
