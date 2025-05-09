#include <iostream>

#include "Obstacle.h"

Obstacle::Obstacle() : tex(), sprite(tex) {
  if (!tex.loadFromFile("lirili.png")) {
    std::cout << "PROBLEMA LIRILI\n";
  }
  sprite.setTexture(tex, true);
  sprite.setScale({0.17, 0.17});
}

void Obstacle::update(float dt) {
  if (sprite.getPosition().x > 350 || sprite.getPosition().x < 0)
    changeDirection();
  // Horizontal movement
  float horizontalMove = (direction == 1) ? speed : -speed;
  sprite.move({horizontalMove * dt, 0});
}

void Obstacle::changeDirection() { direction = !direction; }

void Obstacle::draw(sf::RenderWindow& window) const { window.draw(sprite); }

sf::Vector2f Obstacle::getPosition() const { return sprite.getPosition(); }

void Obstacle::move(float dx, float dy) { sprite.move({dx, dy}); }

sf::FloatRect Obstacle::getBounds() const {
  std::cout << "DIMENSIUNI ELEFANT: " << sprite.getGlobalBounds().size.x << "  "
            << sprite.getGlobalBounds().size.y << std::endl;
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

