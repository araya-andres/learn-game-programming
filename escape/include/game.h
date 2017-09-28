#ifndef GAME_H
#define GAME_H

#include "player.h"
#include <list>

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
    sf::Sprite background_;
};

#endif
