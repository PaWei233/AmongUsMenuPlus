#include "pch-il2cpp.h"
#include "esp_tab.h"
#include "game.h"
#include "state.hpp"
#include "utility.h"

namespace EspTab {

	void Render() {
		if (not IsInGame())
			return;

		bool changed = false;
		if (ImGui::BeginTabItem("Esp")) {

			changed |= ImGui::Checkbox((const char*)u8"启用", &State.ShowEsp);

			changed |= ImGui::Checkbox((const char*)u8"绘制幽灵", &State.ShowEsp_Ghosts);
			changed |= ImGui::Checkbox((const char*)u8"会议期间隐藏", &State.HideEsp_During_Meetings);

			changed |= ImGui::Checkbox((const char*)u8"绘制方框", &State.ShowEsp_Box);
			changed |= ImGui::Checkbox((const char*)u8"绘制追踪线", &State.ShowEsp_Tracers);
			changed |= ImGui::Checkbox((const char*)u8"绘制距离", &State.ShowEsp_Distance);

			changed |= ImGui::Checkbox((const char*)u8"基于身份", &State.ShowEsp_RoleBased);

			ImGui::EndTabItem();
		}
		if (changed) {
			State.Save();
		}
	}
}