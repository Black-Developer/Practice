#include "NPC.h"

bool NPC::HandleMessage(const Telegram& msg)
{
	return m_pStateMachine->HandleMessage(msg);
}

void NPC::Update()
{
	m_pStateMachine->Update(NULL);
}