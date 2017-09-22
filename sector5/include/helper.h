#ifndef HELPER_H
#define HELPER_H

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <iostream>

template<typename T>
std::ostream& operator<<(std::ostream& os, const sf::Vector2<T>& v)
{
    return os << '{' << v.x << ',' << v.y << '}';
}

template<typename T>
std::ostream& operator<<(std::ostream& os, const sf::Rect<T>& r)
{
    return os << '{' << r.left << ',' << r.top << ',' << r.width << ',' << r.height << '}';
}

sf::Vector2f vector2u_to_f(const sf::Vector2u&);

template<typename T>
sf::Vector2<T> rotate_90_degrees(const sf::Vector2<T>& v)
{
    return {v.y, -v.x};
}

#endif
