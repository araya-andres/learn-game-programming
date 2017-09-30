#ifndef PLATFORM_H
#define PLATFORM_H

#include "chipmunk.hpp"

#include "sprite.h"

struct Platform: public Sprite
{
    Platform(sf::RenderWindow&, cp::Space&, double x, double y);
    sf::FloatRect get_bounds();

private:
    cp::Body body_;
    cp::Shape shape_;
};

#endif
