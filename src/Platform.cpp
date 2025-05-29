#include "Platform.h"



template <>
Platform<sf::RectangleShape>::Platform(float x, float y) {
  shape.setSize({60, 10});
  shape.setFillColor(sf::Color::Blue);
  shape.setPosition({x, y});
}

template <>
Platform<sf::CircleShape>::Platform(float x, float y) {
  shape.setRadius(14.0f);
  shape.setFillColor(sf::Color::Red);
  shape.setPosition({x, y});
	shape.setScale({2.0f, 0.5f});
}

template <typename ShapeType>
void Platform<ShapeType>::draw(sf::RenderWindow& window) { window.draw(shape); }


template <typename ShapeType>
void Platform<ShapeType>::setPosition(float x, float y) { shape.setPosition({x, y}); }

template <typename ShapeType>
sf::Vector2f Platform<ShapeType>::getPosition() const { return shape.getPosition(); }

template <typename ShapeType>
sf::FloatRect Platform<ShapeType>::getBounds() const { return shape.getGlobalBounds(); }

template <typename ShapeType>
void Platform<ShapeType>::move(float dx, float dy) { shape.move({dx, dy}); }

template class Platform<sf::RectangleShape>;
template class Platform<sf::CircleShape>;
