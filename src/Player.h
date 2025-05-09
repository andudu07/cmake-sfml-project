#pragma once
#include <SFML/Graphics.hpp>

class Player {
 public:
  Player();
  void update(float dt);
  void draw(sf::RenderWindow& window);
  void jump();
  void move(float dx, float dy);
  sf::FloatRect getBounds() const;
  sf::Vector2f getPosition() const;
  sf::Vector2f getVelocity() const;

 private:
  static sf::Texture tex;
  sf::Sprite sprite;
  sf::Vector2f velocity;
};

