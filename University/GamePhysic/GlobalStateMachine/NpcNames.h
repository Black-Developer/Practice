#pragma once

#include <string>
enum NpcName
{
	ent_Miner_Steve,

	ent_Tissue_Taker
};

inline std::string GetNameOfEntity(int n)
{
	switch (n)
	{
	case NpcName::ent_Miner_Steve:
		return "Miner";
	case NpcName::ent_Tissue_Taker:
		return "Taker";
	default:
		return "UNKOWN";
	}
}