#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

#include "Obstacle.h"
#include "Platform.h"
#include "Player.h"

class Game {
 public:
  Game();
  void run();

 private:
  bool gameOver = 1;
  unsigned int score = 0;
  sf::Font font;
  sf::Text scoreText;
  void processEvents();
  void update(float dt);
  void render();
  void resetPlatforms();

  sf::RenderWindow window;
  Player player;
  std::vector<Platform> platforms;
  Obstacle obstacle;
  const static int platformCount = 10;

  void loadHighScore();
  void saveHighScore();

  sf::Text menuText;
  sf::Text highScoreText;
  unsigned int highScore = 0;
};

