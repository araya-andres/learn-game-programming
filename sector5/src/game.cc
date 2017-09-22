#include "game.h"
#include "helper.h"

const int ENEMY_FREQUENCY = 5;

Game::Game()
    : window_{{800, 600}, "Sector Five"}
    , player_{window_}
{
    initialize();
}

void Game::initialize()
{
    window_.setFramerateLimit(60);
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
                process_key_pressed_event(event.key.code);
                break;
            default:
                // do nothing
                break;
        }
    }
}

void Game::process_key_pressed_event(sf::Keyboard::Key code)
{
    switch (code) {
        case sf::Keyboard::Right:
            player_.turn_right();
            break;
        case sf::Keyboard::Left:
            player_.turn_left();
            break;
        case sf::Keyboard::Up:
            player_.accelerate();
            break;
        default:
            // do nothing
            break;
    }
}

void Game::update()
{
    player_.move();
    enemies_.remove_if([this](const Enemy& e) {
            return e.position().y > window_.getSize().y;
            });
    for (auto& enemy: enemies_) enemy.move();
    if (random(0, 100) < ENEMY_FREQUENCY) {
        enemies_.emplace_front(window_);
    }
}

void Game::render()
{
    window_.clear(sf::Color::Black);
    player_.draw();
    for (auto& enemy: enemies_) enemy.draw();
    window_.display();
}
