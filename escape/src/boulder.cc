#include "boulder.h"
#include "helper.h"

const static double ELASTICITY = .95;
const static double FRICTION = .7;
#if 0
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
        {  2,-11},
    };
#endif

Boulder::Boulder(sf::RenderWindow& window, cp::Space& space, double x, double y)
    : Sprite{window, "images/boulder.png"}
    , body_{cp::Mass{400}, cp::Inertia{4000}}
    , shape_{cp::Shape::makeBox(body_, 35, 25)} // FIXME
{
    body_.setPosition(x, y);
    shape_.setElasticity(ELASTICITY);
    shape_.setFriction(FRICTION);
    space.add(body_);
    space.add(shape_);
    cp::Vect impulse{1.0 * random(10e4) - 5e4, 10e4};
    cp::Vect point{.1 * (random(20, 80) - 40), .0};
    body_.applyImpulseAtLocalPoint(impulse, point);
}

void Boulder::update()
{
    angle_ = body_.getAngle();
    position_ = cp_to_sf(body_.getPosition());
}

sf::FloatRect Boulder::get_bounds()
{
    return sprite_.getGlobalBounds();
}
