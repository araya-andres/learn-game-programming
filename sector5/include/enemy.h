#ifndef ENEMY_H
#define ENEMY_H

#include "game_entity.h"

struct Enemy : public GameEntity
{
    Enemy(sf::RenderWindow&);

    static const float RADIUS;
};

#endif
