#include "Miner.h"
#include <iostream>

using namespace std;

void Miner::Update(int input)
{
	cout << "::Now State:: " << endl;
	switch (input)
	{
	case 1: // 금덩이가 가득 찬 경우
		if (m_Location == location_type::goldmine)
		{
			m_pStateMachine->ChangeState(Mininggold::Instance());
			m_Location = location_type::bank;
		}
			break;
	case 2: // 은행에 보관된 금덩이가 목표치 이상
		if (m_Location == location_type::bank)
		{
			m_pStateMachine->ChangeState(Restathome::Instance());
			m_Location = location_type::home;
		}
		break;
	case 3: // 은행에 보관된 금덩이가 목표치 이하
		if (m_Location == location_type::bank)
		{
			m_pStateMachine->ChangeState(Mininggold::Instance());
			m_Location = location_type::goldmine;
		}
		break;
	case 4: // 피로회복
		if (m_Location == location_type::home)
		{
			m_pStateMachine->ChangeState(Mininggold::Instance());
			m_Location = location_type::goldmine;
		}
		break;
	case 5: // 목마름
		if (m_Location == location_type::goldmine)
		{
			m_pStateMachine->ChangeState(Thirstyreduce::Instance());
			m_Location = location_type::pub;
		}
		break;
	case 6: // 목마르지 않음
		if (m_Location == location_type::pub)
		{
			m_pStateMachine->ChangeState(Mininggold::Instance());
			m_Location = location_type::goldmine;
		}
		break;
	default:
		break;
	}
}