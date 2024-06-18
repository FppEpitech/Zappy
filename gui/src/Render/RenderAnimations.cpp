/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** Animations
*/

#include "Render/Render.hpp"

bool Gui::Render::displayAnimations(Team &team, Player &player)
{
    ModelAnimation anim;

    if (player.getState() == Gui::Player::BEING_EJECTED)
        anim = team.getPlayerModelAnimation()[Gui::Player::IDLE];
    else
        anim = team.getPlayerModelAnimation()[player.getState()];

    if (player.getState() != Gui::Player::WALK && player.getState() != Gui::Player::IDLE &&
        player.getState() != Gui::Player::BEING_EJECTED && player.getCurrentFrame() == anim.frameCount - 1) {
        if (player.getState() == Gui::Player::DEAD) {
            team.removePlayer(player.getId());
            return false;
        }
        player.setState(Gui::Player::IDLE);
        anim = team.getPlayerModelAnimation()[player.getState()];
    }
    anim = displayWalkAnimation(team, player, anim);

    player.setCurrentFrame((player.getCurrentFrame() + 1)%anim.frameCount);
    UpdateModelAnimation(team.getPlayerModel(), anim, player.getCurrentFrame());
    return true;
}

ModelAnimation Gui::Render::displayWalkAnimation(Team &team, Player &player, ModelAnimation anim)
{
    if (player.getState() != Gui::Player::WALK)
        return anim;

    Vector3 playerPos3D = player.getPosition3D();

    if (player.getOrientation() == 3 && playerPos3D.z < (POS_PLAYER.z + player.getPosition().second * SIZE_TILE))
        player.setPosition3D((Vector3){playerPos3D.x, playerPos3D.y, playerPos3D.z + 0.1f});

    else if (player.getOrientation() == 1 && playerPos3D.z > (POS_PLAYER.z + player.getPosition().second * SIZE_TILE))
        player.setPosition3D((Vector3){playerPos3D.x, playerPos3D.y, playerPos3D.z - 0.1f});

    else if (player.getOrientation() == 4 && playerPos3D.x > (POS_PLAYER.x + player.getPosition().first * SIZE_TILE))
        player.setPosition3D((Vector3){playerPos3D.x - 0.1f, playerPos3D.y, playerPos3D.z});

    else if (player.getOrientation() == 2 && playerPos3D.x < (POS_PLAYER.x + player.getPosition().first * SIZE_TILE))
        player.setPosition3D((Vector3){playerPos3D.x + 0.1f, playerPos3D.y, playerPos3D.z});

    else {
        player.setPosition(player.getPosition());
        player.setState(Gui::Player::IDLE);
        anim = team.getPlayerModelAnimation()[player.getState()];
    }
    return anim;
}
