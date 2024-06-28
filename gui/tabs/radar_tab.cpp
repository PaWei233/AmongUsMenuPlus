#include "pch-il2cpp.h"
#include "radar_tab.h"
#include "gui-helpers.hpp"
#include "state.hpp"
#include "utility.h"

namespace RadarTab {
	void Render() {
		if (ImGui::BeginTabItem((const char*)u8"雷达")) {
			ImGui::Dummy(ImVec2(4, 4) * State.dpiScale);
			if (ImGui::Checkbox((const char*)u8"绘制雷达", &State.ShowRadar)) {
				State.Save();
			}
			ImGui::SameLine();
			if (HotKey(State.KeyBinds.Toggle_Radar)) {
				State.Save();
			}

			ImGui::Dummy(ImVec2(7, 7) * State.dpiScale);
			ImGui::Separator();
			ImGui::Dummy(ImVec2(7, 7) * State.dpiScale);

			if (ImGui::Checkbox((const char*)u8"绘制尸体", &State.ShowRadar_DeadBodies)) {
				State.Save();
			}
			if (ImGui::Checkbox((const char*)u8"绘制幽灵", &State.ShowRadar_Ghosts)) {
				State.Save();
			}
			if (ImGui::Checkbox((const char*)u8"右键点击传送", &State.ShowRadar_RightClick_Teleport)) {
				State.Save();
			}

			ImGui::Dummy(ImVec2(7, 7) * State.dpiScale);
			ImGui::Separator();
			ImGui::Dummy(ImVec2(7, 7) * State.dpiScale);

			if (ImGui::Checkbox((const char*)u8"会议期间隐藏雷达", &State.HideRadar_During_Meetings)) {
				State.Save();
			}
			if (ImGui::Checkbox((const char*)u8"绘制玩家图标", &State.RadarDrawIcons)) {
				State.Save();
			}
			if (ImGui::Checkbox((const char*)u8"锁定雷达位置", &State.LockRadar)) {
				State.Save();
			}
			if (ImGui::ColorEdit4("Radar Color",
				(float*)&State.SelectedColor,
				ImGuiColorEditFlags__OptionsDefault
				| ImGuiColorEditFlags_NoInputs
				| ImGuiColorEditFlags_AlphaBar
				| ImGuiColorEditFlags_AlphaPreview)) {
				State.Save();
			}

			ImGui::EndTabItem();
		}
	}
}