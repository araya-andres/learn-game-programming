#include <SFML/Graphics.hpp>
#include "chipmunk.hpp"
#include <vector>

#include "ball.h"
#include "platform.h"

enum {
    WIDTH = 400,
    HEIGHT = 400,
    RADIUS = 5,
};

int main()
{
    cp::Space space;
    space.SetGravity({0, 100});

    Ball ball{space, {.33 * WIDTH, RADIUS}, RADIUS, 1};

    std::vector<Platform> platforms;
    platforms.emplace_back(space, cp::Vect{100, 100}, cp::Vect{200, 200});
    platforms.emplace_back(space, cp::Vect{300, 100}, cp::Vect{200, 300});

    sf::RenderWindow window{{WIDTH, HEIGHT}, ""};
    window.setFramerateLimit(60);

    const auto timeStep = 1.0 / 60;
    while (window.isOpen()) {
        sf::Event e;
        while (window.pollEvent(e)) {
            if (e.type == sf::Event::Closed) window.close();
        }

        ball.update();

        window.clear(sf::Color::Black);
        ball.draw(window);
        for(auto& p : platforms) p.draw(window);
        window.display();

        space.Step(timeStep);
    };
}
