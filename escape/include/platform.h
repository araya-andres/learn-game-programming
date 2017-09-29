#ifndef PLATFORM_H
#define PLATFORM_H

#include "chipmunk.hpp"

#include "game_entity.h"

struct Platform : public GameEntity
{
    Platform(sf::RenderWindow&, cp::Space&, double x, double y);
    void update() override {}

private:
    cp::Body body_;
    cp::Shape shape_;
};

#endif
