#include "boulder.h"
#include "helper.h"

const double ELASTICITY = .95;
const double FRICTION = .7;
const int SPEED_LIMIT = 500;

Boulder::Boulder(sf::RenderWindow& window, cp::Space& space, double x, double y)
    : GameEntity{window, "images/boulder.png"}
    , body_{cp::Mass{400}, cp::Inertia{4000}}
{
    auto shape = cp::Polygon{body_, {
        {-13, -6},
        {-16, -4},
        {-16,  6},
        { -3, 12},
        {  8, 12},
        { 13, 10},
        { 16,  3},
        { 16, -4},
        { 10, -9},
        { -2,-11},
    }};
    shape.setElasticity(ELASTICITY);
    shape.setFriction(FRICTION);
    body_.setPosition(x, y);
    space.add(body_);
    space.add(shape);
}

void Boulder::update()
{
    angle_ = body_.getAngle();
    position_ = cp_to_sf(body_.getPosition());
}
