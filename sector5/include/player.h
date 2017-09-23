#ifndef PLAYER_H
#define PLAYER_H

#include "game_entity.h"

struct Player : public GameEntity
{
    Player(sf::RenderWindow&);
    void move() override;
    void turn_right();
    void turn_left();
    void accelerate();
};

#endif
