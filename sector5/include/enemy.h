#ifndef ENEMY_H
#define ENEMY_H

#include <SFML/Graphics.hpp>

struct Enemy
{
    Enemy(sf::RenderWindow&);
    void draw();
    void move();
    const sf::Vector2f& position() const;

private:
    sf::RenderWindow& window_;
    sf::Texture& texture_;
    sf::Sprite sprite_;
    sf::Vector2f position_;
    float radius_ = 20.0f;
};

#endif
