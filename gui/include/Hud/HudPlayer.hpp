/*
** EPITECH PROJECT, 2024
** Zappy GUI
** File description:
** HudPlayer
*/

#pragma once

#include "Hud/AHud.hpp"

#define HUD_PLAYER_POS Vector2{0, 340}
#define HUD_PLAYER_TEXT_POS Vector2{25, 420}
#define HUD_PLAYER_TEXT_MARGING 30

namespace Gui {

    /**
     * @brief Class to display player's HUD.
     *
     */
    class HudPlayer;
};

class Gui::HudPlayer : public Gui::AHud {

    public:

        HudPlayer(std::shared_ptr<GameData> gameData);
        ~HudPlayer() = default;
        void display();

    private:

        Texture2D   _texture;
        Font        _font;
};
