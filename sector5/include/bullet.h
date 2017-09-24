#ifndef BULLET_H
#define BULLET_H

#include "game_entity.h"

struct Bullet : public GameEntity
{
    Bullet(sf::RenderWindow&, const GameEntity&);
    virtual bool is_marked_for_deletion() const override;
    static const float RADIUS;

private:
    sf::Sound shoot_;
};

#endif
