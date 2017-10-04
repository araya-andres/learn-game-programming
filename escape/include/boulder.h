#ifndef BOULDER_H
#define BOULDER_H

#include "chipmunk.hpp"

#include "drawable.h"
#include "updateable.h"

#include "sprite.h"

struct Boulder: public Drawable, public Updateable
{
    Boulder(sf::RenderWindow&, cp::Space&, double x, double y);
    void update() override;
    void draw() override;
    sf::FloatRect get_bounds() override;

private:
    Sprite sprite_;
    cp::Body body_;
    cp::Shape shape_;
};

#endif
