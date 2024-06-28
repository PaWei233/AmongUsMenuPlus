#include "pch-il2cpp.h"
#include "sabotage_tab.h"
#include "utility.h"
#include "gui-helpers.hpp"
#include "_rpc.h"
#include "game.h"
#include "state.hpp"

namespace SabotageTab {
    void Render() {
        GameOptions options;
        if (IsInGame() && options.GetGameMode() != GameModes__Enum::HideNSeek) {
            if (ImGui::BeginTabItem((const char*)u8"ÆÆ»µ")) {
                ImGui::Dummy(ImVec2(4, 4) * State.dpiScale);
                if (ImGui::Button((const char*)u8"ÐÞ¸´ÆÆ»µ")) {
                    RepairSabotage(*Game::pLocalPlayer);
                }
                ImGui::SameLine();
                if (HotKey(State.KeyBinds.Repair_Sabotage)) {
                    State.Save();
                }
                ImGui::NewLine();
                if (State.mapType == Settings::MapType::Fungle) {
                    if (ImGui::Button((const char*)u8"ÆÆ»µÄ¢¹½»ìºÏÎï")) {
                        State.rpcQueue.push(new RpcRepairSystem(SystemTypes__Enum::Sabotage, SystemTypes__Enum::MushroomMixupSabotage));
                    }
                }
                else if (ImGui::Button((const char*)u8"ÆÆ»µÕÕÃ÷")) {
                    State.rpcQueue.push(new RpcRepairSystem(SystemTypes__Enum::Sabotage, SystemTypes__Enum::Electrical));
                }
                if (State.mapType == Settings::MapType::Ship || State.mapType == Settings::MapType::Hq
                    || State.mapType == Settings::MapType::Fungle) {
                    if (ImGui::Button((const char*)u8"ÆÆ»µ·´Ó¦¶Ñ")) {
                        State.rpcQueue.push(new RpcRepairSystem(SystemTypes__Enum::Sabotage, SystemTypes__Enum::Reactor));
                    }
                } else if (State.mapType == Settings::MapType::Pb) {
                    if (ImGui::Button((const char*)u8"Òý·¢µØÕð")) {
                        State.rpcQueue.push(new RpcRepairSystem(SystemTypes__Enum::Sabotage, SystemTypes__Enum::Laboratory));
                    }
                } else if (State.mapType == Settings::MapType::Airship) {
                    if (ImGui::Button((const char*)u8"ÆÆ»µÖ±Éý»ú")) {
                        State.rpcQueue.push(new RpcRepairSystem(SystemTypes__Enum::Sabotage, SystemTypes__Enum::Reactor));
                    }
                }
                if (State.mapType == Settings::MapType::Ship || State.mapType == Settings::MapType::Hq) {
                    if (ImGui::Button((const char*)u8"ÆÆ»µÑõÆø")) {
                        State.rpcQueue.push(new RpcRepairSystem(SystemTypes__Enum::Sabotage, SystemTypes__Enum::LifeSupp));
                    }
                }
                if (ImGui::Button((const char*)u8"ÆÆ»µÍ¨ÐÅ")) {
                    State.rpcQueue.push(new RpcRepairSystem(SystemTypes__Enum::Sabotage, SystemTypes__Enum::Comms));
                }

                ImGui::Dummy(ImVec2(7, 7) * State.dpiScale);
                ImGui::Separator();
                ImGui::Dummy(ImVec2(7, 7) * State.dpiScale);

                if (ImGui::Checkbox((const char*)u8"½ûÓÃµÆ¹â", &State.DisableLights)) {
                    if (auto switchSystem = (SwitchSystem*)il2cpp::Dictionary((*Game::pShipStatus)->fields.Systems)[SystemTypes__Enum::Electrical]) {
                        auto actualSwitches = switchSystem->fields.ActualSwitches;
                        auto expectedSwitches = switchSystem->fields.ExpectedSwitches;

                        auto switchMask = 1 << ((State.DisableLights ? 0 : 5) & 0x1F);

                        if ((actualSwitches & switchMask) != ((State.DisableLights ? ~expectedSwitches : expectedSwitches) & switchMask))
                            State.rpcQueue.push(new RpcRepairSystem(SystemTypes__Enum::Electrical, 5));
                    }
                }

                ImGui::EndTabItem();
            }
        }
    }
}