#pragma once
#include <vector>

namespace GameTab {
	const std::vector<const char*> KILL_DISTANCE = { "Short", "Medium", "Long" };
	const std::vector<const char*> TASKBARUPDATES = { "Always", "Meetings", "Never" };
	const std::vector<const char*> COLORS = { "Red", "Blue", "Dark Green", "Pink", "Orange", "Yellow", "Black", "White", "Purple", "Brown", "Cyan", "Lime", "Maroon", "Rose", "Banana", "Gray", "Tan", "Coral" };
	const std::vector<const char*> KILL_DISTANCE_CHINESE = { (const char*)u8"��", (const char*)u8"��", (const char*)u8"��" };
	const std::vector<const char*> TASKBARUPDATES_CHINESE = { (const char*)u8"ʵʱ", (const char*)u8"����", (const char*)u8"�Ӳ�" };
	const std::vector<const char*> COLORS_CHINESE = { (const char*)u8"��ɫ", (const char*)u8"��ɫ", (const char*)u8"����ɫ", (const char*)u8"�ۺ�ɫ", (const char*)u8"��ɫ", (const char*)u8"��ɫ", (const char*)u8"��ɫ", (const char*)u8"��ɫ", (const char*)u8"��ɫ", (const char*)u8"��ɫ", (const char*)u8"��ɫ", (const char*)u8"����ɫ", (const char*)u8"���ɫ", (const char*)u8"õ���", (const char*)u8"����ɫ", (const char*)u8"��ɫ", (const char*)u8"��ɫ", (const char*)u8"ɺ����" };
	void Render();
}