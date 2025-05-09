#pragma once
#include <SFML/Graphics.hpp>
#include "Character.h"


class Player : public Character {
 public:
  Player();
  void update(float dt) override;
  void jump();

};

