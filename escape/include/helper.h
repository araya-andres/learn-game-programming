#ifndef HELPER_H
#define HELPER_H

#include "chipmunk.hpp"
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
sf::Vector2<T> rotate_90_degrees_clockwise(const sf::Vector2<T>& v)
{
    return {v.y, -v.x};
}

template<typename T>
sf::Vector2<T> rotate_90_degrees_counterclockwise(const sf::Vector2<T>& v)
{
    return {-v.y, v.x};
}

template<typename T>
sf::Vector3<T> cross_product(const sf::Vector3<T>& a, const sf::Vector3<T>& b)
{
    return {a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z, a.x * b.y - a.y * b.x};
}

template<typename T>
sf::Vector3<T> cross_product(const sf::Vector2<T>& a, const sf::Vector2<T>& b)
{
    return cross_product(sf::Vector3<T>{a.x, a.y, {}}, sf::Vector3<T>{b.x, b.y, {}});
}

sf::Vector2f unit_vector(const float angle);

template<typename T>
T squared_distance(const sf::Vector2<T>& a, const sf::Vector2<T>& b)
{
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

int random(int max);

int random(int min, int max);

sf::Vector2f cp_to_sf(const cp::Vect& v);

#endif
