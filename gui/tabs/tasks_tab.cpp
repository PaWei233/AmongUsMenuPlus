#include "pch-il2cpp.h"
#include "tasks_tab.h"
#include "game.h"
#include "state.hpp"
#include "utility.h"
#include "gui-helpers.hpp"

namespace TasksTab {
	void Render() {
		if (IsInGame() && GetPlayerData(*Game::pLocalPlayer)->fields.Tasks != NULL) {
			if (ImGui::BeginTabItem((const char*)u8"任务")) {
				ImGui::Dummy(ImVec2(4, 4) * State.dpiScale);
				if (!PlayerIsImpostor(GetPlayerData(*Game::pLocalPlayer))) {
					auto tasks = GetNormalPlayerTasks(*Game::pLocalPlayer);

					if (ImGui::Button((const char*)u8"完成所有任务")) {
						for (auto task : tasks) {
							if (task->fields.taskStep != task->fields.MaxStep)
								State.rpcQueue.push(new RpcCompleteTask(task->fields._._Id_k__BackingField));
						}
					}

					ImGui::NewLine();

					for (auto task : tasks) {
						if (ImGui::Button(("Complete##Button" + std::to_string(task->fields._._Id_k__BackingField)).c_str()) && !NormalPlayerTask_get_IsComplete(task, NULL)) {
							State.rpcQueue.push(new RpcCompleteTask(task->fields._._Id_k__BackingField));
						}

						ImGui::SameLine();

						ImGui::TextColored(NormalPlayerTask_get_IsComplete(task, NULL)
							? ImVec4(0.0F, 1.0F, 0.0F, 1.0F)
							: AmongUsColorToImVec4(app::Palette__TypeInfo->static_fields->White)
							, TranslateTaskTypes(task->fields._.TaskType));
					}

					ImGui::Dummy(ImVec2(7, 7) * State.dpiScale);
					ImGui::Separator();
					ImGui::Dummy(ImVec2(7, 7) * State.dpiScale);
				}

				if (ImGui::Button((const char*)u8"播放防护罩动画"))
				{
					State.rpcQueue.push(new RpcPlayAnimation(1));
				}

				if (ImGui::Button((const char*)u8"播放武器动画"))
				{
					State.rpcQueue.push(new RpcPlayAnimation(6));
				}

				if (ImGui::Button((const char*)u8"播放倒垃圾动画"))
				{
					State.rpcQueue.push(new RpcPlayAnimation(10));
				}

				if (ImGui::Checkbox((const char*)u8"播放扫描动画", &State.PlayMedbayScan))
				{
					if (State.PlayMedbayScan)
					{
						State.rpcQueue.push(new RpcSetScanner(true));
					}
					else
					{
						State.rpcQueue.push(new RpcSetScanner(false));
					}
				}

				if (ImGui::Checkbox((const char*)u8"使用中的假画面", &State.FakeCameraUsage))
				{
					State.rpcQueue.push(new RpcRepairSystem(SystemTypes__Enum::Security, (State.FakeCameraUsage ? 1 : 0)));
				}

				ImGui::EndTabItem();
			}
		}
	}
}