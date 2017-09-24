#ifndef GAME_H
#define GAME_H

#include "bullet.h"
#include "enemy.h"
#include "explosion.h"
#include "player.h"
#include <SFML/Graphics.hpp>
#include <list>

struct Game
{
    Game();
    Game(const Game&) = delete;
    Game& operator=(const Game&) = delete;
    void run();
private:
    void initialize();
    void process_events();
    void process_key_event(sf::Keyboard::Key code);
    void update();
    void render();

    sf::RenderWindow window_;
    Player player_;
    std::list<Enemy> enemies_;
    std::list<Bullet> bullets_;
    std::list<Explosion> explosions_;
};

#endif
