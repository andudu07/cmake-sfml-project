#include <iostream>

#include "Player.h"
#define GRAVITY 620.f

sf::Texture Player::tex;

Player::Player() : sprite(tex), velocity({0, 0}) {
  if (!tex.loadFromFile("patapim.png")) {
    std::cout << "PROBLEMA IMAGINE\n";
  }
  sprite.setTexture(tex, true);
  sprite.setScale({0.2, 0.2});
  sprite.setPosition({170, 320});
}

void Player::update(float dt) {
  velocity.y += GRAVITY * dt;
  sprite.move(velocity * dt);

  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left)) {
    sprite.move({-200 * dt, 0});
  }
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right)) {
    sprite.move({200 * dt, 0});
  }

  // Wrap horizontally
  if (sprite.getPosition().x < -30) sprite.setPosition({400, sprite.getPosition().y});
  if (sprite.getPosition().x > 400) sprite.setPosition({-30, sprite.getPosition().y});
}

void Player::draw(sf::RenderWindow& window) { window.draw(sprite); }

void Player::jump() { velocity.y = -550; }

void Player::move(float dx, float dy) { sprite.move({dx, dy}); }

sf::FloatRect Player::getBounds() const { return sprite.getGlobalBounds(); }

sf::Vector2f Player::getPosition() const { return sprite.getPosition(); }

sf::Vector2f Player::getVelocity() const { return velocity; }

