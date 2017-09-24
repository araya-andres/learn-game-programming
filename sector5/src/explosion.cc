#include "explosion.h"

Explosion::Explosion(
        sf::RenderWindow& w,
        const GameEntity& e)
    : Animation{w, "images/explosions.png", false}
    , explosion_{AssetManager::get<sf::SoundBuffer>("sounds/explosion.ogg")}
{
    angle_ = e.angle();
    position_ = e.position();
    velocity_ = e.velocity();
    const auto size = sf::Vector2i{60, 60};
    for (int i = 0; i < 4; i++) {
        add_frames({0, i * size.y}, size, 4);
    }
    explosion_.play();
}

bool Explosion::is_marked_for_deletion() const
{
    if (explosion_.getStatus() == sf::SoundSource::Status::Playing) {
        return false;
    }
    return GameEntity::is_marked_for_deletion();
}
