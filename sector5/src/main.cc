#include "enemy.h"
#include "player.h"
#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <list>

const int MAX_ENEMIES = 3;

int main()
{
    srand(time(nullptr));
    sf::RenderWindow window{{800, 600}, "Sector Five"};
    window.setFramerateLimit(60);
    Player player(window);
    std::list<Enemy> enemies;
    for (int i = 0; i < MAX_ENEMIES; i++) {
        enemies.emplace_front(window);
    }

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Right) {
                    player.turn_right();
                }
                if (event.key.code == sf::Keyboard::Left) {
                    player.turn_left();
                }
                if (event.key.code == sf::Keyboard::Up) {
                    player.accelerate();
                }
            }
        }
        player.move();
        for (auto& enemy: enemies) enemy.move();
        window.clear(sf::Color::Black);
        player.draw();
        for (auto& enemy: enemies) enemy.draw();
        window.display();
    }
}
