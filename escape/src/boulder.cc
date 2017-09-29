#include "boulder.h"
#include "helper.h"

const static double ELASTICITY = .95;
const static double FRICTION = .7;
const static int SPEED_LIMIT = 500;
const static std::vector<cp::Vect> VERTICES {
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
    };

Boulder::Boulder(sf::RenderWindow& window, cp::Space& space, double x, double y)
    : GameEntity{window, "images/boulder.png"}
    , body_{cp::Mass{400}, cp::Inertia{4000}}
    , shape_{body_, VERTICES}
{
    body_.setPosition(x, y);
    shape_.setElasticity(ELASTICITY);
    shape_.setFriction(FRICTION);
    space.add(body_);
    space.add(shape_);
}

void Boulder::update()
{
    angle_ = body_.getAngle();
    position_ = cp_to_sf(body_.getPosition());
}
