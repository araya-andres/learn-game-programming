#include "player.h"
#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window{{800, 600}, "Sector Five"};
    window.setFramerateLimit(60);
    Player player(window);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }
        window.clear(sf::Color::Black);
        player.draw();
        window.display();
    }
}
