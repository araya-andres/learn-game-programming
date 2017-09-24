#include "explosion.h"

Explosion::Explosion(
        sf::RenderWindow& w,
        const sf::Vector2f& position)
    : Animation{w, "images/explosions.png", false}
{
    position_ = position;
    const auto size = sf::Vector2i{60, 60};
    for (int i = 0; i < 4; i++) {
        add_frames({0, i * size.y}, size, 4);
    }
}
