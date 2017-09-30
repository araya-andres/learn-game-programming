#include "wall.h"

Wall::Wall(cp::Space& space, float left, float top, float width, float height)
    : body_(cp::Body::makeStatic())
    , shape_(cp::Shape::makeBox(body_, width, height))
    , rect_{left, top, width, height}
{
    body_.setPosition(left + .5 * width, top + .5 * height);
    space.add(body_);
    space.add(shape_);
}

sf::FloatRect Wall::get_bounds()
{
    return rect_;
}
