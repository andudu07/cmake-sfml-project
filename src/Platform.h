#pragma once
#include <SFML/Graphics.hpp>


template <typename ShapeType>
class Platform {
 public:
  bool scored = false;
  Platform(float x, float y);
  void draw(sf::RenderWindow& window);
  void setPosition(float x, float y);
  sf::Vector2f getPosition() const;
  sf::FloatRect getBounds() const;
  void move(float dx, float dy);

 private:
 	ShapeType shape;
};

