#pragma once
class Miner;

class State
{
public:
	State() {}
	virtual ~State() {} // 자식 클래스에서 상속 받을 때, 종료 이후 호출 되어 소멸자를 실행하여 리소스를 해제합니다.

	virtual void Enter(Miner*) = 0;
	virtual void Execute(Miner*) = 0;
	virtual void Exit(Miner*) = 0;
};