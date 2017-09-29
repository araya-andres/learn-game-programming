#ifndef GAME_H
#define GAME_H

#include "chipmunk.hpp"
#include <list>

#include "boulder.h"
#include "platform.h"
#include "player.h"
#include "wall.h"

struct Game
{
    Game(const Game&) = delete;
    Game& operator=(const Game&) = delete;
    static Game& instance();
    void run();
private:
    Game();

    void process_events();
    void process_key_event(sf::Keyboard::Key code);
    void update();
    void render();

    sf::RenderWindow window_;
    Player player_;
    cp::Space space_;
    sf::Sprite background_;
    std::list<Boulder> boulders_;
    std::list<Platform> platforms_;
    Wall floor_;
    Wall left_wall_;
    Wall right_wall_;
};

#endif
