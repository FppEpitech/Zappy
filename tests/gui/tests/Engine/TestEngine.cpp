/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** TestEngine
*/

#include "Engine/Engine.hpp"
#include "CriterionHeaders.hpp"

namespace Gui {

    class Render {

        public:
            Render(std::shared_ptr<GameData> gameData) : _gameData(gameData){};
            ~Render() = default;
            void draw() {};
        private:
            std::shared_ptr<GameData> _gameData;
    };
};

Test(Engine, constructor, .timeout = 5)
{
    Gui::Network net(4242, "127.0.0.1");
    Gui::Engine engine(std::make_shared<Gui::INetwork>(net));

    cr_assert_not_null(&engine);
}
