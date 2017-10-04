#ifndef PLATFORM_H
#define PLATFORM_H

#include <SFML/Graphics.hpp>

#include "drawable.h"
#include "updateable.h"

struct Platform: public Drawable, public Updateable
{
    Platform(sf::RenderWindow&, cp::Space&, double x, double y);
    ~Platform();
    void update() override;
    void draw() override;
    sf::FloatRect get_bounds() override;

protected:
    struct Impl;
    Impl* pimpl_;
};

#endif
