#ifndef __INPUTMANAGER_H__
#define __INPUTMANAGER_H__

#include <dinput.h>
#include <functional>

#pragma comment(lib, "dinput8")
#pragma comment(lib, "dxguid")

class InputManager
{
private:
	InputManager();
	InputManager(const InputManager& ref) {}
	InputManager& operator=(const InputManager& ref) {}
	~InputManager() {}
public:
	static InputManager& getInstance()
	{
		static InputManager instance;
		return instance;
	}
};

#endif //!__INPUTMANAGER_H__
