#pragma once
#include <vector>

namespace GameTab {
	const std::vector<const char*> KILL_DISTANCE = { "Short", "Medium", "Long" };
	const std::vector<const char*> TASKBARUPDATES = { "Always", "Meetings", "Never" };
	const std::vector<const char*> COLORS = { "Red", "Blue", "Dark Green", "Pink", "Orange", "Yellow", "Black", "White", "Purple", "Brown", "Cyan", "Lime", "Maroon", "Rose", "Banana", "Gray", "Tan", "Coral" };
	const std::vector<const char*> KILL_DISTANCE_CHINESE = { (const char*)u8"短", (const char*)u8"中", (const char*)u8"长" };
	const std::vector<const char*> TASKBARUPDATES_CHINESE = { (const char*)u8"实时", (const char*)u8"会议", (const char*)u8"从不" };
	const std::vector<const char*> COLORS_CHINESE = { (const char*)u8"红色", (const char*)u8"蓝色", (const char*)u8"深绿色", (const char*)u8"粉红色", (const char*)u8"橙色", (const char*)u8"黄色", (const char*)u8"黑色", (const char*)u8"白色", (const char*)u8"紫色", (const char*)u8"棕色", (const char*)u8"青色", (const char*)u8"黄绿色", (const char*)u8"红褐色", (const char*)u8"玫瑰粉", (const char*)u8"蕉黄色", (const char*)u8"灰色", (const char*)u8"茶色", (const char*)u8"珊瑚红" };
	void Render();
}