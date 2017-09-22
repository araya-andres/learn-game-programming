#include "helper.h"
#include <cassert>
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
