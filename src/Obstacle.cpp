#include <iostream>

#include "Obstacle.h"

Obstacle::Obstacle() {
 	loadTexture("lirili.png"); 
	sprite.setScale({0.17, 0.17});
	start_pos = {0, -100};
	velocity = {150, 0};
}

void Obstacle::update(float dt) {
  if (sprite.getPosition().x > 350 || sprite.getPosition().x < 0)
    changeDirection();
  // Horizontal movement
  float horizontalMove = (direction == 1) ? velocity.x : -velocity.x;
  sprite.move({horizontalMove * dt, 0});
}

void Obstacle::changeDirection() { direction = !direction; }




sf::FloatRect Obstacle::getBounds() const {

  sf::FloatRect smallRect = sprite.getGlobalBounds();
  smallRect.size = {55, 55};
  smallRect.position.x += 20;
  smallRect.position.y += 15;
  return smallRect;
}

bool Obstacle::shouldRemove() const { return sprite.getPosition().y > 600; }

bool Obstacle::getDirection() const { return direction; }

bool Obstacle::isActive() const { return active; }

void Obstacle::activate() {
  active = 1;
  sprite.setPosition(start_pos);
}

void Obstacle::deactivate() {
  active = 0;
  direction = 1;
  sprite.setPosition({0, 0});
}

