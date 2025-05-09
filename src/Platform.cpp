#include "Platform.h"

Platform::Platform(float x, float y) {
  shape.setSize({60, 10});
  shape.setFillColor(sf::Color::Blue);
  shape.setPosition({x, y});
}

void Platform::draw(sf::RenderWindow& window) { window.draw(shape); }

void Platform::setPosition(float x, float y) { shape.setPosition({x, y}); }

sf::Vector2f Platform::getPosition() const { return shape.getPosition(); }

sf::FloatRect Platform::getBounds() const { return shape.getGlobalBounds(); }

void Platform::move(float dx, float dy) { shape.move({dx, dy}); }

