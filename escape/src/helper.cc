#include "helper.h"
#include <cassert>
#include <cmath>
#include <cstdlib>

sf::Vector2f vector2u_to_f(const sf::Vector2u& v)
{
    return sf::Vector2f(v.x, v.y);
}

int random(int min, int max)
{
    assert(min < max);
    return rand() % (max - min) + min;
}

sf::Vector2f unit_vector(const float angle)
{
    const auto radians = M_PI * angle / 180;
    return sf::Vector2f(cos(radians), sin(radians));
}

sf::Vector2f cp_to_sf(const cp::Vect& v)
{
    return sf::Vector2f(v.x, v.y);
}
