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
    , chip_{window_, space_, 70, 700}
    , floor_{space_, 0, HEIGHT - THIKNESS, WIDTH, THIKNESS}
    , left_wall_{space_, 0, 0, THIKNESS, HEIGHT - THIKNESS}
    , right_wall_{space_, WIDTH - THIKNESS, 0, THIKNESS, HEIGHT - THIKNESS}
{
    window_.setFramerateLimit(FRAMERATE);
    space_.setDamping(DAMPING);
    space_.setGravity({.0, GRAVITY});
    set_background();
    make_platforms();
}

Game& Game::instance()
{
    static Game g;
    return g;
}

void Game::set_background()
{
    auto& texture = AssetManager::get<sf::Texture>("images/background.png");
    texture.setRepeated(true);
    background_.setTexture(texture);
    background_.setTextureRect({0, 0, WIDTH, HEIGHT});
}

void Game::make_platforms()
{
    platforms_.emplace_front(window_, space_, 150, 700);
    platforms_.emplace_front(window_, space_, 320, 650);
    platforms_.emplace_front(window_, space_, 150, 500);
    platforms_.emplace_front(window_, space_, 470, 550);
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
            chip_.move_right();
            break;
        case sf::Keyboard::Left:
            chip_.move_left();
            break;
        case sf::Keyboard::Space:
            chip_.jump();
            break;
        default:
            // do nothing
            break;
    }
}

void Game::update()
{
    space_.step(1.0 / FRAMERATE);
    chip_.check_footing(get_bounds());
    chip_.update();
    for (auto& b: boulders_) {
        b.update();
    }
    if (random(0, 100) <= BOULDER_FREQUENCY) {
        boulders_.emplace_front(window_, space_, 1.0 * random(200, 400), 20);
    }
}

void Game::render()
{
    window_.clear(sf::Color::Black);
    window_.draw(background_);
    chip_.draw();
    for (auto& p: platforms_) {
        p.draw();
    }
    for (auto& b: boulders_) {
        b.draw();
    }
    window_.display();
}

std::vector<sf::FloatRect> Game::get_bounds()
{
    std::vector<sf::FloatRect> bounds{floor_.get_bounds()};
    std::transform(
            platforms_.begin(), platforms_.end(),
            std::back_inserter(bounds),
            [](Platform& p) { return p.get_bounds(); }
            );
    std::transform(
            boulders_.begin(), boulders_.end(),
            std::back_inserter(bounds),
            [](Boulder& b) { return b.get_bounds(); }
            );
    return bounds;
}
