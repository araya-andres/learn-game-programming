#ifndef BOULDER_H
#define BOULDER_H

#include "chipmunk.hpp"
#include "sprite.h"
#include "updateable.h"

struct Boulder: public Sprite, public Updateable
{
    Boulder(sf::RenderWindow&, cp::Space&, double x, double y);
    void update() override;
    sf::FloatRect get_bounds();

private:
    cp::Body body_;
    cp::Shape shape_;
};

#endif
