#ifndef BALL_H
#define BALL_H

#include <SFML/Graphics.hpp>
#include "chipmunk.hpp"

struct Ball
{
    Ball(cp::Space&, const cp::Position&, cpFloat radius, cpFloat mass);
    void update();
    void draw(sf::RenderWindow&);
private:
    cpVect position_;
    cp::Body body_;
    cp::Circle shape_;
    sf::CircleShape sprite_;
    sf::Color color_ = sf::Color::White;
};

#endif
