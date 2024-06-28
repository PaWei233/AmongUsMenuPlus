#pragma once
#include <vector>
#include "utility.h"

namespace HostTab {
	const std::vector<const char*> MAP_NAMES = { "The Skeld", "Mira HQ", "Polus", /*"Dleks",*/ "Airship", "The Fungle" };
	const std::vector<const char*> IMPOSTOR_AMOUNTS = { "1", "2", "3" };
	const std::vector<const char*> ROLE_NAMES = { "Random", "Crewmate", "Scientist", "Engineer", "Imposter", "Shapeshifter" };
	const std::vector<const char*> ROLE_NAMES_CHINESE = { (const char*)u8"���", (const char*)u8"��Ա", (const char*)u8"��ѧ��", (const char*)u8"����ʦ", (const char*)u8"αװ��", (const char*)u8"������" };
	void Render();
	const ptrdiff_t GetRoleCount(RoleType role);
}