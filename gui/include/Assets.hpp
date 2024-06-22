/*
** EPITECH PROJECT, 2024
** Zappy GUI
** File description:
** Assets
*/

#pragma once

#include "Config.hpp"

#include <vector>
#include <string>

#define PATH_ASSETS                     "gui/assets/"

#define PATH_RESOURCES                  "resources/"
#define PATH_PLAYER                     "player/"
#define PATH_TILE                       "tile/"
#define PATH_DECORATION                 "decoration/"
#define PATH_HUD                        "hud/"
#define PATH_HELP                       "help/"
#define PATH_END                        "end/"

#define PNG_CURSOR                      PATH_ASSETS PATH_HUD "cursor.png"
#define PNG_END_HUD                     PATH_ASSETS PATH_END "end_hud.png"
#define PNG_HUD                         PATH_ASSETS PATH_HUD "hud.png"
#define PNG_FOOD                        PATH_ASSETS PATH_HUD "food.png"
#define PNG_LINEMATE                    PATH_ASSETS PATH_HUD "linemate.png"
#define PNG_DERAUMERE                   PATH_ASSETS PATH_HUD "deraumere.png"
#define PNG_MENDIANE                    PATH_ASSETS PATH_HUD "mendiane.png"
#define PNG_PHIRAS                      PATH_ASSETS PATH_HUD "phiras.png"
#define PNG_SIBUR                       PATH_ASSETS PATH_HUD "sibur.png"
#define PNG_THYSTAME                    PATH_ASSETS PATH_HUD "thystame.png"
#define PNG_PLAYER                      PATH_ASSETS PATH_HUD "player.png"
#define PNG_TILE                        PATH_ASSETS PATH_HUD "tile.png"
#define PNG_EGG                         PATH_ASSETS PATH_HUD "egg.png"
#define FONT_HUD                        PATH_ASSETS PATH_HUD "SimplyMono-Bold.ttf"

#define PNG_HELP                        PATH_ASSETS PATH_HELP "help_menu.png"
#define PNG_HELP_KEYS                   PATH_ASSETS PATH_HELP "keys.png"
#define PNG_HUD                         PATH_ASSETS PATH_HUD "hud.png"
#define PNG_FOOD                        PATH_ASSETS PATH_HUD "food.png"
#define PNG_LINEMATE                    PATH_ASSETS PATH_HUD "linemate.png"
#define PNG_DERAUMERE                   PATH_ASSETS PATH_HUD "deraumere.png"
#define PNG_MENDIANE                    PATH_ASSETS PATH_HUD "mendiane.png"
#define PNG_PHIRAS                      PATH_ASSETS PATH_HUD "phiras.png"
#define PNG_SIBUR                       PATH_ASSETS PATH_HUD "sibur.png"
#define PNG_THYSTAME                    PATH_ASSETS PATH_HUD "thystame.png"
#define PNG_PLAYER                      PATH_ASSETS PATH_HUD "player.png"
#define PNG_TILE                        PATH_ASSETS PATH_HUD "tile.png"
#define FONT_HUD                        PATH_ASSETS PATH_HUD "SimplyMono-Bold.ttf"

#define MODEL_TILE                      PATH_ASSETS PATH_TILE "tile.glb"
#define MODEL_FOOD                      PATH_ASSETS PATH_RESOURCES "food.glb"
#define MODEL_LINEMATE                  PATH_ASSETS PATH_RESOURCES "linemate.glb"
#define MODEL_MENDIANE                  PATH_ASSETS PATH_RESOURCES "mendiane.glb"
#define MODEL_PHIRAS                    PATH_ASSETS PATH_RESOURCES "phiras.glb"
#define MODEL_SIBUR                     PATH_ASSETS PATH_RESOURCES "sibur.glb"
#define MODEL_THYSTAME                  PATH_ASSETS PATH_RESOURCES "thystame.glb"
#define MODEL_DERAUMERE                 PATH_ASSETS PATH_RESOURCES "deraumere.glb"
#define MODEL_PLAYER                    PATH_ASSETS PATH_PLAYER "player.glb"
#define MODEL_EGG                       PATH_ASSETS PATH_PLAYER "egg.glb"
#define MODEL_TREE                      PATH_ASSETS PATH_DECORATION "tree.glb"
#define MODEL_LANTERN                   PATH_ASSETS PATH_DECORATION "lantern.glb"

#define SCALE_FOOD                      (Vector3){1, 0.5, 1}
#define SCALE_LINEMATE                  (Vector3){0.1, 0.1, 0.1}
#define SCALE_MENDIANE                  (Vector3){0.1, 0.1, 0.1}
#define SCALE_PHIRAS                    (Vector3){0.001, 0.001, 0.005}
#define SCALE_SIBUR                     (Vector3){0.01, 0.01, 0.01}
#define SCALE_THYSTAME                  (Vector3){2, 2, 2}
#define SCALE_DERAUMERE                 (Vector3){0.5, 0.5, 0.5}
#define SCALE_PLAYER                    (Vector3){0.5, 0.5, 0.5}
#define SCALE_EGG                       (Vector3){0.5, 0.5, 0.5}
#define SCALE_TREE                      (Vector3){1, 1, 1}
#define SCALE_LANTERN                   (Vector3){1, 1, 1}

#define ROTATION_ANGLE_FOOD             45
#define ROTATION_ANGLE_LINEMATE         270
#define ROTATION_ANGLE_MENDIANE         0
#define ROTATION_ANGLE_PHIRAS           270
#define ROTATION_ANGLE_SIBUR            270
#define ROTATION_ANGLE_THYSTAME         270
#define ROTATION_ANGLE_DERAUMERE        90
#define ROTATION_ANGLE_PLAYER           0
#define ROTATION_ANGLE_EGG              270
#define ROTATION_ANGLE_TREE             0
#define ROTATION_ANGLE_LANTERN          0

#define ROTATION_AXIS_FOOD              (Vector3){0, 1, 0}
#define ROTATION_AXIS_LINEMATE          (Vector3){1, 0, 0}
#define ROTATION_AXIS_MENDIANE          (Vector3){1, 0, 0}
#define ROTATION_AXIS_PHIRAS            (Vector3){1, 0, 0}
#define ROTATION_AXIS_SIBUR             (Vector3){1, 0, 0}
#define ROTATION_AXIS_THYSTAME          (Vector3){1, 0, 0}
#define ROTATION_AXIS_DERAUMERE         (Vector3){1, 0, 0}
#define ROTATION_AXIS_PLAYER            (Vector3){0, 1, 0}
#define ROTATION_AXIS_EGG               (Vector3){1, 0, 0}
#define ROTATION_AXIS_TREE              (Vector3){1, 0, 0}
#define ROTATION_AXIS_LANTERN           (Vector3){1, 0, 0}

#define POS_FOOD                        (Vector3){0.5, -0.1, 1.5}
#define POS_LINEMATE                    (Vector3){1, -0.3, -0.5}
#define POS_MENDIANE                    (Vector3){2, -0.25, -0.5}
#define POS_PHIRAS                      (Vector3){0.5, -0.3, -1.5}
#define POS_SIBUR                       (Vector3){1.5, -0.3, -1.5}
#define POS_THYSTAME                    (Vector3){1, 0, -2}
#define POS_DERAUMERE                   (Vector3){2, -0.3, -2}
#define POS_PLAYER                      (Vector3){0, -0.25, 0}
#define POS_EGG                         (Vector3){0.5, 0, 0.5}
#define POS_TREE                        (Vector3){2, -0.3, 2}
#define POS_LANTERN                     (Vector3){1, -0.3, 2}
#define POS_Y_DELIMITATION              -0.27f

#define PLAYER_TEXT_SIZE                40
#define PLAYER_TEXT_SIZE_RATIO          1.5f

#define HELP_BACKGROUND_SCALE           3.5f
#define HELP_BACKGROUND_TEXTURE_SIZE    (Vector2){400 * HELP_BACKGROUND_SCALE, 200 * HELP_BACKGROUND_SCALE}
#define HELP_BACKGROUND_POSITION        (Vector2){WINDOW_WIDTH / 2 - HELP_BACKGROUND_TEXTURE_SIZE.x / 2, WINDOW_HEIGHT / 2 - HELP_BACKGROUND_TEXTURE_SIZE.y / 2}
#define HELP_TEXT_POSITION_LEFT         (Vector2){HELP_BACKGROUND_POSITION.x + 270, HELP_BACKGROUND_POSITION.y + 180}
#define HELP_TEXT_POSITION_RIGHT        (Vector2){HELP_TEXT_POSITION_LEFT.x + 610, HELP_TEXT_POSITION_LEFT.y}
#define HELP_TEXT_SPACING               30
#define HELP_TITLE_OFFSET               90

#define END_HUD_TEXT_SIZE               40

static std::vector<std::string> globalControlsTexts = {
    "Move the camera in the space",
    "Move the camera up",
    "Move the camera down",
    "Switch on/off the debug display",
    "Reset the HUD from tile view to game view",
    "Switch on/off the help HELP",
    "Increase the render distance",
    "Decrease the render distance",
    "Increase the time unit",
    "Decrease the time unit",
    "Select the player point of view",
    "Select the tile to display its HUD",
};

static std::vector<std::string> playerControlsTexts = {
    "Change the player point of view",
    "Get off the player point of view",
    "Switch to the next player",
    "Switch to the previous player",
    "Switch on/off the player vision",
};
