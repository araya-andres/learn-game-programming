#ifndef DRAWABLE_H
#define DRAWABLE_H

#include "SFML/Graphics.hpp"

struct Drawable
{
    virtual ~Drawable() {}
    virtual void draw() = 0;
    virtual sf::FloatRect get_bounds() = 0;
};

#endif
