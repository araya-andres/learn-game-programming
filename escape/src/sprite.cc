#include "asset_manager.h"
#include "sprite.h"

Sprite::Sprite(sf::RenderWindow& w, const std::string& fname)
    : window_{w}
    , texture_{AssetManager::get<sf::Texture>(fname)}
{
    auto origin = texture_.getSize() / 2u;
    sprite_.setTexture(texture_);
    sprite_.setOrigin(origin.x, origin.y);
}

void Sprite::draw()
{
    sprite_.setRotation(angle_);
    sprite_.setPosition(position_);
    window_.draw(sprite_);
}
