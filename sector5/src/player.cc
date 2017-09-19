#include "asset_manager.h"
#include "player.h"

Player::Player(sf::RenderWindow& w)
    : window_(w)
    , texture_(AssetManager::getTexture("images/ship.png"))
{
    const auto origin = texture_.getSize() / 2u;
    sprite_.setTexture(texture_);
    sprite_.setOrigin(origin.x, origin.y);
}

void Player::draw()
{
    sprite_.setPosition(x_, y_);
    sprite_.rotate(angle_);
    window_.draw(sprite_);
}
