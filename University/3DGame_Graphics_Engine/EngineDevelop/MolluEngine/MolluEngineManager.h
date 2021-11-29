#ifndef __MOLLUENGINEMANAGER_H__
#define __MOLLUENGINEMANAGER_H__

#include "MolluEngine.h"
#include "IRenderer.h"


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
	void Init(IRenderer*, int, char**, int, int);
	void InitCamera(IRenderer*);
	void Loop(IRenderer* render);
	IRenderer* RenderingWithDX();
	IRenderer* RenderingWithGL();
};


#endif // !__MOLLUENGINEMANAGER_H__
