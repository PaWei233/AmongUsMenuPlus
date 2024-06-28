﻿#include "pch-il2cpp.h"
#include "settings_tab.h"
#include "utility.h"
#include "gui-helpers.hpp"
#include "state.hpp"
#include "game.h"
#include "achievements.hpp"
#include "DirectX.h"
#include "imgui/imgui_impl_win32.h" // ImGui_ImplWin32_GetDpiScaleForHwnd
#include "theme.hpp" // ApplyTheme

namespace SettingsTab {
	void Render() {
		if (ImGui::BeginTabItem((const char*)u8"设置")) {
			ImGui::Dummy(ImVec2(4, 4) * State.dpiScale);
			ImGui::Text((const char*)u8"显示/隐藏 菜单按键绑定：");
			ImGui::SameLine();
			if (HotKey(State.KeyBinds.Toggle_Menu)) {
				State.Save();
			}

			ImGui::Text((const char*)u8"显示/隐藏 控制台绑定键：");
			ImGui::SameLine();
			if (HotKey(State.KeyBinds.Toggle_Console)) {
				State.Save();
			}

			ImGui::Dummy(ImVec2(7, 7) * State.dpiScale); 
			ImGui::Separator();
			ImGui::Dummy(ImVec2(7, 7) * State.dpiScale);
			if (ImGui::Checkbox((const char*)u8"按DPI调整", &State.AdjustByDPI)) {
				if (!State.AdjustByDPI) {
					State.dpiScale = 1.0f;
				}
				else {
					State.dpiScale = ImGui_ImplWin32_GetDpiScaleForHwnd(DirectX::window);
				}
				State.dpiChanged = true;
				State.Save();
			}
#ifdef _DEBUG
			static const std::vector<const char*> DPI_SCALING_LEVEL = { "100%", "125%", "150%", "175%", "200%", "225%", "250%", "275%", "300%" };
			ImGui::SameLine();
			int scaleIndex =(int(std::clamp(State.dpiScale, 1.0f, 3.0f) * 100.0f) - 100) / 25;
			if (CustomListBoxInt("Scaling Level", &scaleIndex, DPI_SCALING_LEVEL, 100 * State.dpiScale)) {
				State.dpiScale = (scaleIndex * 25 + 100) / 100.0f;
				State.dpiChanged = true;
			}
#endif
			ImGui::Dummy(ImVec2(4, 4) * State.dpiScale);

#ifdef _DEBUG
			if (ImGui::Checkbox("Show Debug Tab", &State.showDebugTab)) {
				State.Save();
			}
			ImGui::Dummy(ImVec2(4, 4) * State.dpiScale);
#endif
			//Change this to in game only once account is overridden
			{
				char* nameBuffer[12]{ const_cast<char*>(State.userName.c_str()) };
				if (ImGui::InputText((const char*)u8"玩家名称", *nameBuffer, IM_ARRAYSIZE(nameBuffer))) {
					
					State.userName = std::string(*nameBuffer);
				}
			}
			if (State.userName.empty()) {
				State.userName = GetPlayerName();
			}

			ImGui::SameLine();
			if (ImGui::Button((const char*)u8"设置名字"))
			{
				State.SetUserName = true;
			}

			ImGui::Checkbox((const char*)u8"mod模式", &State.ModMode); //已修改，Mod模式选择框
			
			ImGui::Dummy(ImVec2(7, 7) * State.dpiScale);
			ImGui::Separator();
			ImGui::Dummy(ImVec2(7, 7) * State.dpiScale);

			if (Achievements::IsSupported()
				&& ImGui::Button((const char*)u8"解锁所有成就"))
			{
				Achievements::UnlockAll();
			}

			ImGui::EndTabItem();
		}
	}
}