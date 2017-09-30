#ifndef SPRITE_H
#define SPRITE_H

#include <SFML/Graphics.hpp>
#include <string>

#include "drawable.h"

struct Sprite: public Drawable
{
    Sprite(sf::RenderWindow&, const std::string& fname);
    void draw() override;

protected:
    sf::RenderWindow& window_;
    sf::Texture& texture_;
    sf::Sprite sprite_;
    sf::Vector2f position_;
    float angle_ = 0;
};

#endif
