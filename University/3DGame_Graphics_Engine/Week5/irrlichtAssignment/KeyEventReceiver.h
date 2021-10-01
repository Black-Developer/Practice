#ifndef __KEYEVENTRECEIVER_H__
#define __KEYEVENTRECEIVER_H__

#include "IEventReceiver.h"

using namespace irr;



class KeyEventReceiver : public IEventReceiver
{
public:
	virtual bool OnEvent(const SEvent& event);
	virtual bool IsKeyDown(EKEY_CODE keyCode) const;
	KeyEventReceiver();

private:
	bool KeyIsDown[KEY_KEY_CODES_COUNT];
};
#endif // !__KEYEVENTRECEIVER_H__