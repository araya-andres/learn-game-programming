#include "asset_manager.h"
#include "game.h"
#include "helper.h"

Game::Game()
    : window_{{800, 600}, "Escape"}
    , player_{window_}
{
    initialize();
}

void Game::initialize()
{
    window_.setFramerateLimit(60);
}

Game& Game::instance()
{
    static Game g;
    return g;
}

void Game::run()
{
    while (window_.isOpen()) {
        process_events();
        update();
        render();
    }
}

void Game::process_events()
{
    sf::Event event;
    while (window_.pollEvent(event)) {
        switch (event.type) {
            case sf::Event::Closed:
                window_.close();
                break;
            case sf::Event::KeyPressed:
                process_key_event(event.key.code);
                break;
            default:
                // do nothing
                break;
        }
    }
}

void Game::process_key_event(sf::Keyboard::Key code)
{
    switch (code) {
        case sf::Keyboard::Right:
            break;
        case sf::Keyboard::Left:
            break;
        case sf::Keyboard::Up:
            break;
        case sf::Keyboard::Space:
            break;
        default:
            // do nothing
            break;
    }
}

void Game::update()
{
    player_.update();
}

void Game::render()
{
    window_.clear(sf::Color::Black);
    player_.draw();
    window_.display();
}
