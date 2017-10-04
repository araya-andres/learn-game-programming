#include "chipmunk.hpp"

#include "platform.h"
#include "sprite.h"

static const double ELASTICITY = .8;
static const double FRICTION = .7;
static const int WIDTH = 96;
static const int HEIGHT = 16;

struct Platform::Impl
{
    Impl(sf::RenderWindow& window, cp::Space& space, double x, double y)
        : sprite_{window, "images/platform.png"}
        , body_{cp::Body::makeStatic()}
        , shape_{cp::Shape::makeBox(body_, WIDTH, HEIGHT)}
    {
        sprite_.set_position(x, y);
        body_.setPosition(x, y);
        shape_.setElasticity(ELASTICITY);
        shape_.setFriction(FRICTION);
        space.add(body_);
        space.add(shape_);
    }

    void draw()
    {
        sprite_.draw();
    }

    sf::FloatRect get_bounds()
    {
        return sprite_.get_bounds();
    }

private:
    Sprite sprite_;
    cp::Body body_;
    cp::Shape shape_;
};

Platform::Platform(sf::RenderWindow& window, cp::Space& space, double x, double y)
    : pimpl_{new Impl{window, space, x, y}}
{
}

Platform::~Platform()
{
    delete pimpl_;
}

void Platform::draw()
{
    pimpl_->draw();
}

void Platform::update()
{
}

sf::FloatRect Platform::get_bounds()
{
    return pimpl_->get_bounds();
}
