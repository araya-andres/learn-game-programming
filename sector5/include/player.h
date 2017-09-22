#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>

struct Player
{
    Player(sf::RenderWindow&);
    void draw();
    void turn_right();
    void turn_left();
    void move();
    void accelerate();

private:
    sf::RenderWindow& window_;
    sf::Texture& texture_;
    sf::Sprite sprite_;
    sf::Vector2f position_;
    sf::Vector2f velocity_;
    float angle_;
    float radius_ = 20.0f;
};

#endif
