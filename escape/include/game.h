#ifndef GAME_H
#define GAME_H

#include "chipmunk.hpp"
#include <list>

#include "boulder.h"
#include "chip.h"
#include "platform.h"
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

    void make_platforms();
    void set_background();
    std::vector<sf::FloatRect> get_bounds();

    sf::RenderWindow window_;
    cp::Space space_;
    Chip chip_;
    std::list<Boulder> boulders_;
    std::list<Platform> platforms_;
    Wall floor_;
    Wall left_wall_;
    Wall right_wall_;
    sf::Sprite background_;
};

#endif
