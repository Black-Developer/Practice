#ifndef __MOLLUENGINEMANAGER_H__
#define __MOLLUENGINEMANAGER_H__

#include "MolluEngine.h"

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
	void Init(IRenderer*, int, char**, int, int);
	void InitCamera(IRenderer*);
	void Loop(IRenderer* render);
public:
	IRenderer* GetRednerer() const { return renderer; }
	IRenderer* SetRenderer(ERenderer);
private:
	IRenderer* renderer;
};


#endif // !__MOLLUENGINEMANAGER_H__
