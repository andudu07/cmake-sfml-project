#pragma once
#include <SFML/Graphics.hpp>
#include "Character.h"

class Obstacle : public Character {
 public:
  Obstacle();
  void update(float dt) override;
  sf::FloatRect getBounds() const override;
  bool shouldRemove() const;
  bool getDirection() const;
  bool isActive() const;
  void activate();
  void deactivate();
  void changeDirection();

 private:
  bool active = 0;
  bool direction = 1;
  
};

