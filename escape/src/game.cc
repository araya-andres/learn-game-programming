#include "asset_manager.h"
#include "game.h"
#include "helper.h"

enum
{
    FRAMERATE = 60,
    GRAVITY = 400,
    HEIGHT = 800,
    WIDTH = 800,
};

const double DAMPING = .9;

Game::Game()
    : window_{{WIDTH, HEIGHT}, "Escape"}
    , player_{window_}
{
    window_.setFramerateLimit(FRAMERATE);
    space_.SetDamping(DAMPING);
    space_.SetGravity({.0, GRAVITY});
    auto& texture = AssetManager::get<sf::Texture>("images/background.png");
    texture.setRepeated(true);
    background_.setTexture(texture);
    background_.setTextureRect({0, 0, WIDTH, HEIGHT});
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
    window_.draw(background_);
    /* player_.draw(); */
    window_.display();
}
