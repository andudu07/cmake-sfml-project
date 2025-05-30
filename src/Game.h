#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "Obstacle.h"
#include "Platform.h"
#include "Player.h"
#include "PlatformPool.h"


class Game {
 public:
  Game();
  void run();

 private:
  PlatformPool platformPool;
	bool gameOver = 1;
  unsigned int score = 0;
  sf::Font font;
  sf::Text scoreText;
  void processEvents();
  void update(float dt);
  void render();
  void resetPlatforms();
	template <typename T, typename U>
	bool checkCollision(const T& obj1, const U& obj2){
  	return obj1.getBounds().findIntersection(obj2.getBounds()).has_value();
	}

  sf::RenderWindow window;
  Player player;
  std::vector<Platform<sf::RectangleShape>> platforms;
	Platform<sf::CircleShape> bouncer;
  Obstacle obstacle;
  const static int platformCount = 15;
	const static int bouncerCount = 1;

  void loadHighScore();
  void saveHighScore();

  sf::Text menuText;
  sf::Text highScoreText;
  unsigned int highScore = 0;
};

