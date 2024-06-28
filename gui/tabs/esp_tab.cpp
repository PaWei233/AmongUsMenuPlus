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

			changed |= ImGui::Checkbox((const char*)u8"����", &State.ShowEsp);

			changed |= ImGui::Checkbox((const char*)u8"��������", &State.ShowEsp_Ghosts);
			changed |= ImGui::Checkbox((const char*)u8"�����ڼ�����", &State.HideEsp_During_Meetings);

			changed |= ImGui::Checkbox((const char*)u8"���Ʒ���", &State.ShowEsp_Box);
			changed |= ImGui::Checkbox((const char*)u8"����׷����", &State.ShowEsp_Tracers);
			changed |= ImGui::Checkbox((const char*)u8"���ƾ���", &State.ShowEsp_Distance);

			changed |= ImGui::Checkbox((const char*)u8"�������", &State.ShowEsp_RoleBased);

			ImGui::EndTabItem();
		}
		if (changed) {
			State.Save();
		}
	}
}