#include "asset_manager.h"
#include "game.h"
#include "helper.h"

enum
{
    BOULDER_FREQUENCY = 1,
    FRAMERATE = 60,
    GRAVITY = 400,
    HEIGHT = 800,
    WIDTH = 800,
    THIKNESS = 5,
};

const double DAMPING = .9;

Game::Game()
    : window_{{WIDTH, HEIGHT}, "Escape"}
    , player_{window_}
    , floor_{space_, 0, HEIGHT - THIKNESS, WIDTH, THIKNESS}
    , left_wall_{space_, 0, 0, THIKNESS, HEIGHT - THIKNESS}
    , right_wall_{space_, WIDTH - THIKNESS, 0, THIKNESS, HEIGHT - THIKNESS}
{
    window_.setFramerateLimit(FRAMERATE);
    space_.setDamping(DAMPING);
    space_.setGravity({.0, GRAVITY});
    auto& texture = AssetManager::get<sf::Texture>("images/background.png");
    texture.setRepeated(true);
    background_.setTexture(texture);
    background_.setTextureRect({0, 0, WIDTH, HEIGHT});
    platforms_.emplace_front(window_, space_, 150, 700);
    platforms_.emplace_front(window_, space_, 320, 650);
    platforms_.emplace_front(window_, space_, 150, 500);
    platforms_.emplace_front(window_, space_, 470, 550);
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
    space_.step(1.0 / FRAMERATE);
    for (auto& b : boulders_) {
        b.update();
    }
    if (random(0, 100) <= BOULDER_FREQUENCY) {
        boulders_.emplace_front(window_, space_, random(200, 400), 20);
    }
}

void Game::render()
{
    window_.clear(sf::Color::Black);
    window_.draw(background_);
    for (auto& b : boulders_) {
        b.draw();
    }
    for (auto& p : platforms_) {
        p.draw();
    }
    window_.display();
}
