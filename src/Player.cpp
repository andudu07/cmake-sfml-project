#include <iostream>

#include "Player.h"
#define GRAVITY 620.f

//sf::Texture Character::tex;

Player::Player() {
	loadTexture("patapim.png");
	velocity = {0, 0};
	start_pos = {170, 320};
  sprite.setScale({0.2, 0.2});
  sprite.setPosition(start_pos);
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


void Player::jump(float dt) { velocity.y = dt; }



