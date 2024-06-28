#pragma once
#include <vector>
#include "utility.h"

namespace HostTab {
	const std::vector<const char*> MAP_NAMES = { "The Skeld", "Mira HQ", "Polus", /*"Dleks",*/ "Airship", "The Fungle" };
	const std::vector<const char*> IMPOSTOR_AMOUNTS = { "1", "2", "3" };
	const std::vector<const char*> ROLE_NAMES = { "Random", "Crewmate", "Scientist", "Engineer", "Imposter", "Shapeshifter" };
	const std::vector<const char*> ROLE_NAMES_CHINESE = { (const char*)u8"随机", (const char*)u8"船员", (const char*)u8"科学家", (const char*)u8"工程师", (const char*)u8"伪装者", (const char*)u8"变形者" };
	void Render();
	const ptrdiff_t GetRoleCount(RoleType role);
}