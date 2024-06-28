#include "pch-il2cpp.h"
#include "self_tab.h"
#include "game.h"
#include "gui-helpers.hpp"
#include "utility.h"
#include "state.hpp"
#include "logger.h"

extern void RevealAnonymousVotes(); // in MeetingHud.cpp

namespace SelfTab {
    void Render() {
        if (ImGui::BeginTabItem((const char*)u8"����")) {
            ImGui::Dummy(ImVec2(4, 4) * State.dpiScale);
            if (ImGui::Checkbox((const char*)u8"�����Ұ", &State.MaxVision)) {
                State.Save();
            }
            if (ImGui::Checkbox((const char*)u8"͸��", &State.Wallhack)) {
                State.Save();
            }

            if (ImGui::Checkbox((const char*)u8"���������", &State.FreeCam)) {
                if (IsInGame()) {
                    State.playerToFollow = PlayerSelection();
                }
            }
            ImGui::SameLine();
            if (HotKey(State.KeyBinds.Toggle_Freecam)) {
                State.Save();
            }

            ImGui::SameLine(145.0f * State.dpiScale);
            SteppedSliderFloat("  ", &State.FreeCamSpeed, 0.5f, 3.f, 0.25f, "%.2fx Speed", ImGuiSliderFlags_Logarithmic | ImGuiSliderFlags_NoInput);

            ImGui::Checkbox((const char*)u8"����", &State.EnableZoom);
            ImGui::SameLine();
            HotKey(State.KeyBinds.Toggle_Zoom);

            ImGui::SameLine(145.0f * State.dpiScale);
            SteppedSliderFloat("   ", &State.CameraHeight, 1.0f, 20.0f, 1.0f, "%.2fx Zoom", ImGuiSliderFlags_Logarithmic | ImGuiSliderFlags_NoInput);

            ImGui::Dummy(ImVec2(7, 7) * State.dpiScale);
            ImGui::Separator();
            ImGui::Dummy(ImVec2(7, 7) * State.dpiScale);

            if (ImGui::Checkbox((const char*)u8"ʼ����ʾ���찴ť", &State.ChatAlwaysActive)) {
                State.Save();
            }
            ImGui::SameLine();
            if (ImGui::Checkbox((const char*)u8"������������ճ��", &State.ChatPaste)) {
                State.Save();
            }
            if (ImGui::Checkbox((const char*)u8"��ȡ������Ϣ", &State.ReadGhostMessages)) {
                State.Save();
            }

            ImGui::Dummy(ImVec2(7, 7) * State.dpiScale);
            ImGui::Separator();
            ImGui::Dummy(ImVec2(7, 7) * State.dpiScale);

            if (ImGui::Checkbox((const char*)u8"�������", &State.RevealRoles)) {
                State.Save();
            }
            ImGui::SameLine(120.0f * State.dpiScale);
            if (ImGui::Checkbox((const char*)u8"��д���", &State.AbbreviatedRoleNames))
            {
                State.Save();
            }
            if (ImGui::Checkbox((const char*)u8"����ͶƱ", &State.RevealVotes)) {
                State.Save();
            }
            if (!IsInGame() && !IsInLobby() 
                || GameOptions().GetGameMode() != GameModes__Enum::Normal
                || GameOptions().GetBool(app::BoolOptionNames__Enum::AnonymousVotes)) {
                ImGui::SameLine(120.0f * State.dpiScale);
                if (ImGui::Checkbox((const char*)u8"��������ͶƱ", &State.RevealAnonymousVotes)) {
                    State.Save();
                    RevealAnonymousVotes();
                }
            }

            if (ImGui::Checkbox((const char*)u8"��������", &State.ShowGhosts)) {
                State.Save();
            }
            ImGui::SameLine(120.0f * State.dpiScale);
            if (ImGui::Checkbox((const char*)u8"��������", &State.ShowProtections))
            {
                State.Save();
            }
            ImGui::SameLine(260.0f * State.dpiScale);
            if (ImGui::Checkbox((const char*)u8"������ɱ��ȴ", &State.ShowKillCD)) {
                State.Save();
            }

            if (ImGui::Checkbox((const char*)u8"����ͨ���", &State.UnlockVents)) {
                State.Save();
            }
            ImGui::SameLine(120.0f * State.dpiScale);
            if (ImGui::Checkbox((const char*)u8"��ͨ����ƶ�", &State.MoveInVent) && IsInGame()) {
                if (!State.MoveInVent && (State.InMeeting || (*Game::pLocalPlayer)->fields.inVent)) {
                    (*Game::pLocalPlayer)->fields.moveable = false;
                }
            }

            if (ImGui::Checkbox((const char*)u8"��ǽ", &State.NoClip)) {
                if (State.LobbyTimer == 0 || !IsInLobby()) {
                    if (!IsInGame() && !IsInLobby()) State.NoClip = false;
                    else {
                        if (!(GetPlayerData(*Game::pLocalPlayer)->fields.IsDead)) {
                            if (State.NoClip)
                                app::GameObject_set_layer(app::Component_get_gameObject((Component_1*)(*Game::pLocalPlayer), NULL), app::LayerMask_NameToLayer(convert_to_string("Ghost"), NULL), NULL);
                            else
                                app::GameObject_set_layer(app::Component_get_gameObject((Component_1*)(*Game::pLocalPlayer), NULL), app::LayerMask_NameToLayer(convert_to_string("Players"), NULL), NULL);
                        }
                    }
                } else State.NoClip = false;
            }
            ImGui::SameLine();
            HotKey(State.KeyBinds.Toggle_Noclip);

            if (ImGui::Checkbox((const char*)u8"�Ҽ���������", &State.RightClickTeleport)) {
                State.Save();
            }

            ImGui::EndTabItem();
        }
    }
}