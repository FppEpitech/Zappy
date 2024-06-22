/*
** EPITECH PROJECT, 2024
** Zappy GUI
** File description:
** Render
*/

#pragma once


#include "raylib.h"
#include "Config.hpp"
#include "Hud/HudGame.hpp"
#include "Hud/HudTile.hpp"
#include "Hud/HudPlayer.hpp"
#include "Hud/HudHelp.hpp"
#include "Hud/HudEnd.hpp"
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

        /**
         * @brief Set the Render Distance value.
         *
         * @param renderDistance New render distance value.
         */
        void setRenderDistance(size_t renderDistance);

        /**
         * @brief Get the Render Distance value.
         *
        */
        size_t getRenderDistance() const;

        /**
         * @brief Check if the camera is in player pov.
         *
         * @return true - Camera is in player pov.
         * @return false - Camera is not in player pov.
         * @note The player pov is the first person, second person and third person.
         */
        bool isCameraInPlayerPov() const;

        /**
         * @brief Change the player point of view.
         *
         * @param playerId Player id to select.
         * @note The player point of view is the first person, second person and third person.
        */
        void changePlayerPOV(size_t playerId);

        /**
         * @brief Sets the Pov of the player.
         *
         * @param playerId Player id to select.
        */
        void setPlayerPov(size_t playerId);

        /**
         * @brief Change the camera to the player.
         *
         * @param player Player to select.
        */
        void changePOVToFirstPerson(size_t id);

        /**
         * @brief Change the camera to the player.
         *
         * @param player Player to select.
        */
        void changePOVToSecondPerson(size_t id);

        /**
         * @brief Change the camera to the player.
         *
         * @param player Player to select.
         */
        void changePOVToThirdPerson(size_t id);

        /**
         * @brief Get the Time Unit value.
         *
         * @return size_t - Time unit value.
        */
        size_t getTimeUnit() const;

        /**
         * @brief Set the Time Unit value.
         *
         * @param timeUnit New time unit value.
        */
        void setTimeUnit(size_t timeUnit);

        /**
         * @brief Set the Player Vision value.
         *
         * @param isPlayerVision New player vision value.
         * @note True to display player vision.
         * @note False to not display player vision.
        */
        void setPlayerVision(bool isPlayerVision);

        /**
         * @brief Get the Player Vision value.
         *
         * @return true - Display player vision.
         * @return false - Do not display player vision.
        */
        bool getPlayerVision() const;

        /**
         * @brief Set the Help Menu value.
         *
         * @param isHelpMenu New help menu value.
         */
        void setHelpMenu(bool isHelpMenu);

        /**
         * @brief Get the Help Menu value.
         *
         * @return true - Display the help menu.
         * @return false - Do not display the help menu.
         */
        bool getHelpMenu() const;

        /**
         * @brief Draw the end of the game.
         *
         */
        void drawEnd() const;

    private:

        UserCamera                                  _camera;            //!< Camera of the scene.
        bool                                        _isDebug;           //!< Display or not the debug informations.
        std::shared_ptr<GameData>                   _gameData;          //!< GameData class to store the game's data.
        std::shared_ptr<Decoration>                 _decoration;        //!< Decoration to display;
        std::vector<std::shared_ptr<Gui::IHud>>     _hudList;           //!< List of huds.
        size_t                                     _renderDistance;     //!< Distance to render from the 3d position of the camera.
        bool                                        _isHelpMenu;        //!< Display the help menu.

        Model                                       _tileModel;         //!< Model to display tiles.
        Model                                       _foodModel;         //!< Model to display foods.
        Model                                       _linemateModel;     //!< Model to display linemates.
        Model                                       _mendianeModel;     //!< Model to display mendianes.
        Model                                       _phirasModel;       //!< Model to display phiras.
        Model                                       _siburModel;        //!< Model to display siburs.
        Model                                       _thystameModel;     //!< Model to display thystames.
        Model                                       _deraumereModel;    //!< Model to display deraumeres.
        Texture2D                                   _cursorTexture;     //!< Cursor texture.
        std::vector<Vector2>                        _playerVisionPositions;   //!< Player vision positions.
        bool                                        _endHudSet;         //!< End hud set.

        /**
         * @brief Load the models to draw.
         *
         */
        void LoadModels();

        /**
         * @brief Display HUD infos related to player's pov.
         *
         */
        void displayHUD();

        /**
         * @brief Display the debug interface.
         *
         */
        void displayDebug();

        /**
         * @brief Display players.
         *
         */
        void displayPlayers();

        /**
         * @brief Display player level.
         *
         * @param player Player to display level.
         * @param position Position to display the level.
         * @param team Team for the player 3d position.
         */
        void displayPlayerLevel(Player &player, Vector3 position, Team &team);

        /**
         * @brief Display player broadcast.
         *
         * @param team Team for the player 3d position.
         * @param player Player to display broadcast.
         */
        void displayPlayerBroadcast(Team &team, Player &player);

        /**
         * @brief Display the map.
         *
         */
        void displayMap();

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
        bool displayAnimations(Team &team, Player &player);

        /**
         * @brief Display walk animation.
         *
         * @param team Team for model.
         * @param player Player to draw animation.
         * @param anim Animation Model.
         * @return ModelAnimation - Animation.
         */
        ModelAnimation displayWalkAnimation(Team &team, Player &player, ModelAnimation anim);

        /**
         * @brief Display the cursor.
         *
         */
        void displayCursor();

        /**
         * @brief Get the closest tile from the camera.
         *
         * @return std::pair<std::size_t, std::size_t> - Tile position.
        */
        std::pair<std::size_t, std::size_t> getCameraTile();

        /**
         * @brief Get the positions of objects in player vision.
         *
         * @return size_t - Player id.
        */
        std::vector<Vector2> getPositionsInPlayerVision(size_t playerId);

        /**
         * @brief Check if a position is in player vision.
         *
         * @param position Position to check.
         * @return true - Position is in player vision.
         * @return false - Position is not in player vision.
        */
        bool isInArrayPlayerVision(std::pair<size_t, size_t> pos);

        /**
         * @brief Get the line of vision.
         *
         * @param pos Position to check.
         * @param sizeOfHalf size of the half of the line of vision.
         * @param orientation orientation of the vision.
         */
        std::vector<Vector2> getLineOfVision(Vector2 pos, size_t sizeOfHalf, size_t orientation);

        /**
         * @brief Add a position to the vision.
         *
         * @param vision Vision to add the position.
         * @param pos Positions to add.
         * @return std::vector<Vector2> - Vision with the position added.
        */
        std::vector<Vector2> addVisionPosition(std::vector<Vector2> vision, std::vector<Vector2> pos);

        /**
         * @brief Display the help menu.
         *
         */
        void displayHelpMenu(std::shared_ptr<IHud> hud);

        /**
         * @brief Display the help menu controls.
         *
         * @param position Position to display the help menu.
         */
        void displayHelpMenuControls(Vector2 position);
};
