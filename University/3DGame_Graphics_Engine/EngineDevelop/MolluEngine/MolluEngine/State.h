#ifndef __STATE_H__
#define __STATE_H__

class State
{
public:
	State() {}
	virtual ~State() {}
	virtual void Enter() = 0;
	virtual void Execute() = 0;
	virtual void Exit() = 0;
};

#endif // !__STATE_H__