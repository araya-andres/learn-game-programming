#ifndef SPRITE_H
#define SPRITE_H

#include <SFML/Graphics.hpp>
#include <string>

struct Sprite
{
    Sprite(sf::RenderWindow&, const std::string& fname);
    void draw();
    void set_position(float x, float y);
    void set_angle(float);
    sf::FloatRect get_bounds();

protected:
    sf::RenderWindow& window_;
    sf::Texture& texture_;
    sf::Sprite sprite_;
    sf::Vector2f position_;
    float angle_ = 0;
};

#endif
