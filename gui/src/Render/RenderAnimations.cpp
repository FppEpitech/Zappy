/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** Animations
*/

#include "Render/Render.hpp"

void Gui::Render::displayAnimations(Team &team, Player &player)
{
    ModelAnimation anim = team.getPlayerModelAnimation()[player.getState()];
    player.setCurrentFrame((player.getCurrentFrame() + 1)%anim.frameCount);
    UpdateModelAnimation(team.getPlayerModel(), anim, player.getCurrentFrame());
}
