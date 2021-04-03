#include "Miner.h"

void Miner::Update(int events)
{
	m_pStateMachine->Update(events);
}

bool Miner::HandleMessage(const Telegram& msg)
{
	return m_pStateMachine->HandleMessage(msg);
}