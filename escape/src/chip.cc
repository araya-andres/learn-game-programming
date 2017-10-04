#include <cmath>

#include "asset_manager.h"
#include "chip.h"

const double RUN_IMPULSE = 600;
const double JUMP_IMPULSE = 3600;
const double FLY_IMPULSE = 60;
const double AIR_JUMP_IMPULSE = 1200;
const double SPEED_LIMIT = 4000;
const double FRICTION = .7;
const double ELASTICITY = .2;

Chip::Chip(sf::RenderWindow& w, cp::Space& space, double x, double y)
    : window_{w}
    , body_{50.0, 1/.0}
    , shape_{cp::Shape::makeBox(body_, 20, 65)}
{
    body_.setPosition(x, y);
    shape_.setElasticity(ELASTICITY);
    shape_.setFriction(FRICTION);
    space.add(body_);
    space.add(shape_);
    initialize_animations();
}

void Chip::initialize_animations()
{
    const sf::Vector2i frame_size{40, 65};
    const std::string fname{"images/chip.png"};
    animation_.try_emplace(Action::JUMP,
            window_, fname,
            Animation::make_frames({}, frame_size, 4)
            );
    animation_.try_emplace(Action::RUN,
            window_, fname,
            Animation::make_frames({0, frame_size.y}, frame_size, 3)
            );
    animation_.try_emplace(Action::STAND,
            window_, fname,
            Animation::make_frames({3 * frame_size.x, frame_size.y}, frame_size, 1),
            false
            );
}

void Chip::move_right()
{
    const auto impulse = off_ground_ ? FLY_IMPULSE : RUN_IMPULSE;
    body_.applyImpulse({impulse, .0});
}

void Chip::move_left()
{
    const auto impulse = off_ground_ ? FLY_IMPULSE : RUN_IMPULSE;
    body_.applyImpulse({-impulse, .0});
}

void Chip::jump()
{
    const auto impulse = off_ground_ ? AIR_JUMP_IMPULSE : JUMP_IMPULSE;
    body_.applyImpulse({.0, -impulse});
}

void Chip::update()
{
    const auto position = body_.getPosition();
    const auto velocity = cp::clamp(body_.getVelocity(), SPEED_LIMIT);
    body_.setVelocity(velocity);
    if (velocity.y != 0) { // free falling
        current_action_ = JUMP;
    } else if (velocity.x != 0) {
        current_action_ = RUN;
    } else {
        current_action_ = STAND;
    }
    auto& animation = animation_.at(current_action_);
    animation.set_position(position.x, position.y);
    animation.set_scale(velocity.x >= 0 ? 1 : -1, 1);
    animation.update();
}

void Chip::draw()
{
    animation_.at(current_action_).draw();
}

sf::FloatRect Chip::get_bounds()
{
    return {}; // FIXME
}

void Chip::check_footing(const std::vector<sf::FloatRect>& bounds)
{
    const auto position = body_.getPosition();
    const auto is_touching = [&position](const sf::FloatRect& footing){
        const auto dx = abs(position.x - footing.left);
        const auto dy = abs(position.y - footing.top);
        return dx < .5 * footing.width && dy < .5 * footing.height;
    };
    off_ground_ = none_of(bounds.cbegin(), bounds.cend(), is_touching);
}
