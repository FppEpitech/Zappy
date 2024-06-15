/*
** EPITECH PROJECT, 2024
** Zappy GUI
** File description:
** Render
*/

#pragma once

#define WINDOW_WIDTH 1920
#define WINDOW_HEIGHT 1080
#define WINDOW_TITLE "Zappy GUI"

#include "raylib.h"
#include "Hud/HudGame.hpp"
#include "Hud/HudTile.hpp"
#include "Hud/HudPlayer.hpp"
#include "Render/Decoration.hpp"
#include "Render/UserCamera.hpp"
#include "GameDatas/GameData.hpp"

#include <functional>
#include <unordered_map>

namespace Gui {

    /**
     * @brief Render class to display Zappy.
     *
     */
    class Render;
};

class Gui::Render {

    public:

        /**
         * @brief Construct a new Render object.
         *
         */
        Render(std::shared_ptr<GameData> gameData);

        /**
         * @brief Destroy the Render object.
         *
         */
        ~Render();

        /**
         * @brief Check if the window is open.
         *
         * @return true - the window is open
         * @return false - the window is closed
         */
        bool isOpen();

        /**
         * @brief Draw the scene.
         *
         */
        void draw();

        /**
         * @brief Get the Camera object.
         *
         * @return std::shared_ptr<Camera> - camera
         */
        std::shared_ptr<Camera> getCamera();

        /**
         * @brief Set the Is Debug object.
         *
         * @param isDebug New Is Debug value to set.
         */
        void setIsDebug(bool isDebug);

        /**
         * @brief Get the Is Debug object.
         *
         * @return true - diplay debug
         * @return false - do not display debug
         */
        bool getIsDebug(void);

        /**
         * @brief Set the Type object.
         *
         * @param type Type to set.
         */
        void setCameraType(Gui::UserCamera::CameraType type);

        /**
         * @brief Get the Type object.
         *
         * @return CameraType - Camera type.
         */
        Gui::UserCamera::CameraType getCameraType() const;

        /**
         * @brief Set the Camera player pov id.
         *
         * @param id Id of the player.
         */
        void setCameraPlayerPov(std::size_t id);

        /**
         * @brief Get the Camera player pov id.
         *
         * @return std::size_t - Id of the player.
         */
        std::size_t getCameraPlayerPov() const;

        /**
         * @brief Set the Camera Tile object.
         *
         * @param pos Tile position.
         */
        void setCameraTile(std::pair<std::size_t, std::size_t> pos);

        /**
         * @brief Get the Camera Tile object.
         *
         * @return std::pair<std::size_t, std::size_t> - Tile position.
         */
        std::pair<std::size_t, std::size_t> getCameraTile() const;

        /**
         * @brief Get the Tile model.
         *
        */
        Model getTileModel() const;

    private:

        UserCamera                                  _camera;            // Camera of the scene.
        bool                                        _isDebug;           // Display or not the debug informations.
        std::shared_ptr<GameData>                   _gameData;          // GameData class to store the game's data.
        std::shared_ptr<Decoration>                 _decoration;        // Decoration to display;
        std::vector<std::shared_ptr<Gui::IHud>>     _hudList;           // List of huds.

        Model                                       _tileModel;         // Model to display tiles.
        Model                                       _foodModel;         // Model to display foods.
        Model                                       _linemateModel;     // Model to display linemates.
        Model                                       _mendianeModel;     // Model to display mendianes.
        Model                                       _phirasModel;       // Model to display phiras.
        Model                                       _siburModel;        // Model to display siburs.
        Model                                       _thystameModel;     // Model to display thystames.
        Model                                       _deraumereModel;    // Model to display deraumeres.

        /**
         * @brief Load the models to draw.
         *
         */
        void LoadModels(void);

        /**
         * @brief Display HUD infos related to player's pov.
         *
         */
        void displayHUD(void);

        /**
         * @brief Display the debug interface.
         *
         */
        void displayDebug(void);

        /**
         * @brief Display players.
         *
         */
        void displayPlayers(void);

        /**
         * @brief Display the map.
         *
         */
        void displayMap(void);

        /**
         * @brief Display a Tile.
         *
        */
        void displayTile(Tile tile);

        /**
         * @brief Display the eggs.
         *
         * @param tile Tile with eggs.
        */
        void displayEggs(Tile tile) const;

        /**
         * @brief Display the food.
         *
         * @param tile Tile with food.
         */
        void displayFood(Tile tile) const;

        /**
         * @brief Display resources.
         *
         * @param tile Tile with resources.
         */
        void displayResources(Tile tile) const;

        /**
         * @brief Display Linemate.
         *
         * @param tile Tile with resources.
         */
        void displayLinemate(Tile tile) const;

        /**
         * @brief Display Mendiane.
         *
         * @param tile Tile with resources.
         */
        void displayMendiane(Tile tile) const;

        /**
         * @brief Display Phiras.
         *
         * @param tile Tile with resources.
         */
        void displayPhiras(Tile tile) const;

        /**
         * @brief Display Sibur.
         *
         * @param tile Tile with resources.
         */
        void displaySibur(Tile tile) const;

        /**
         * @brief Display Thystam.
         *
         * @param tile Tile with resources.
         */
        void displayThystame(Tile tile) const;

        /**
         * @brief Display Deraumere.
         *
         * @param tile Tile with resources.
         */
        void displayDeraumere(Tile tile) const;

        /**
         * @brief Display animations.
         *
         * @param team Team for model.
         * @param player Player to draw animation.
         */
        void displayAnimations(Team &team, Player &player);
};
