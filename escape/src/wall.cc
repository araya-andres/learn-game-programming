#include "wall.h"

Wall::Wall(cp::Space& space, double left, double top, double width, double height)
    : body_(cp::Body::makeStatic())
    , shape_(cp::Shape::makeBox(body_, width, height))
{
    body_.setPosition(left + .5 * width, top + .5 * height);
    space.add(body_);
    space.add(shape_);
}
