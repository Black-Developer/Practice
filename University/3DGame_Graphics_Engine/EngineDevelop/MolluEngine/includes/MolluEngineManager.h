#ifndef __MOLLUENGINEMANAGER_H__
#define __MOLLUENGINEMANAGER_H__

#include "MolluEngine.h"
#include "IRenderer.h"

enum ERenderer
{
	isValid = 0,
	E_OPENGL = 1,
	E_DIRECTX = 2
};

class MolluEngineManager
{
private:
	MolluEngineManager() {}
	MolluEngineManager(const MolluEngineManager& ref) {}
	MolluEngineManager& operator=(const MolluEngineManager& ref) {}
	~MolluEngineManager() {}
public:
	static MolluEngineManager& getInstance()
	{
		static MolluEngineManager instance;
		return instance;
	}
public:
	void Init(int, char**, int, int);
	void InitCamera();
	void Loop(IRenderer* render);
public:
	IRenderer* GetRednerer() const { return renderer; }
	IRenderer* SetRenderer(ERenderer);
private:
	IRenderer* renderer;
};


#endif // !__MOLLUENGINEMANAGER_H__
