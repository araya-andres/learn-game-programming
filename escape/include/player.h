#ifndef PLAYER_H
#define PLAYER_H

#include "game_entity.h"

struct Player : public GameEntity
{
    Player(sf::RenderWindow&);
    void update() override;

    static const float RADIUS;
};

#endif
