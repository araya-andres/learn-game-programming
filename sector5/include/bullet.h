#ifndef BULLET_H
#define BULLET_H

#include "game_entity.h"

struct Bullet : public GameEntity
{
    Bullet(sf::RenderWindow&, const GameEntity&);
};

#endif
