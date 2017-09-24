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
            player_.turn_right();
            break;
        case sf::Keyboard::Left:
            player_.turn_left();
            break;
        case sf::Keyboard::Up:
            player_.accelerate();
            break;
        case sf::Keyboard::Space:
            bullets_.emplace_front(window_, player_);
            break;
        default:
            // do nothing
            break;
    }
}

void Game::update()
{
    player_.move();

    const auto min_squared_distance = (Enemy::RADIUS + Bullet::RADIUS) * (Enemy::RADIUS + Bullet::RADIUS);
    for (auto& e: enemies_) {
        for (auto& b: bullets_) {
            if (squared_distance(e.position(), b.position()) < min_squared_distance) {
                e.mark_for_deletion();
                b.mark_for_deletion();
                explosions_.emplace_front(window_, e.position());
                continue;
            }
        }
    }

    const sf::FloatRect boundary(.0f, .0f, window_.getSize().x, window_.getSize().y);
    auto is_marked_for_deletion_or_out_of_the_screen = [&boundary](const GameEntity& e) {
            return e.is_marked_for_deletion() || !boundary.contains(e.position());
    };
    bullets_.remove_if(is_marked_for_deletion_or_out_of_the_screen);
    for (auto& b: bullets_) {
        b.move();
    }

    enemies_.remove_if(is_marked_for_deletion_or_out_of_the_screen);
    for (auto& e: enemies_) {
        e.move();
    }

    explosions_.remove_if(is_marked_for_deletion_or_out_of_the_screen);
    for (auto& e: explosions_) {
        e.update();
    }

    if (random(0, 100) < ENEMY_FREQUENCY) {
        enemies_.emplace_front(window_);
    }
}

void Game::render()
{
    window_.clear(sf::Color::Black);
    player_.draw();
    for (auto& bullet: bullets_) {
        bullet.draw();
    }
    for (auto& enemy: enemies_) {
        enemy.draw();
    }
    for (auto& explosion: explosions_) {
        explosion.draw();
    }
    window_.display();
}
