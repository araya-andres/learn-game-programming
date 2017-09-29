#include "platform.h"

static const double ELASTICITY = .8;
static const double FRICTION = .7;
static const int WIDTH = 96;
static const int HEIGHT = 16;

Platform::Platform(sf::RenderWindow& window, cp::Space& space, double x, double y)
    : GameEntity{window, "images/platform.png"}
    , body_{cp::Body::makeStatic()}
    , shape_{cp::Shape::makeBox(body_, WIDTH, HEIGHT)}
{
    position_.x = x;
    position_.y = y;
    body_.setPosition(x, y);
    shape_.setElasticity(ELASTICITY);
    shape_.setFriction(FRICTION);
    space.add(body_);
    space.add(shape_);
}
