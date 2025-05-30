#include <fstream>
#include <iostream>
#include <optional>

#define NORMAL_V -550
#define BOUNCE_V -1000
#include "Game.h"

Game::Game()
    : window(sf::VideoMode({400, 600}), ""),
      font(),
      scoreText(font),
      menuText(font),
      highScoreText(font),
			bouncer(0, 0),
			platformPool(30){
  if (!font.openFromFile("ARIAL.TTF")) {
    std::cout << "PROBLEMA FONT\n";
  }

  scoreText.setFont(font);
  scoreText.setString("Score: 0");
  scoreText.setCharacterSize(24);
  scoreText.setFillColor(sf::Color::Black);
  scoreText.setPosition({10, 10});

  menuText.setFont(font);
  menuText.setString("Press ENTER to Start");
  menuText.setCharacterSize(30);
  menuText.setFillColor(sf::Color::Black);
  menuText.setPosition({57, 280});

  highScoreText.setFont(font);
  loadHighScore();
  highScoreText.setString("High Score: " + std::to_string(highScore));
  highScoreText.setCharacterSize(24);
  highScoreText.setFillColor(sf::Color::Green);
  highScoreText.setPosition({10, 10});

  resetPlatforms();
}

void Game::run() {
  sf::Clock clock;
  while (window.isOpen()) {
    float dt = clock.restart().asSeconds();
    processEvents();

    if (!gameOver) {
      update(dt);
    }

    render();
  }
}

void Game::processEvents() {
  while (auto event = window.pollEvent()) {
    if (event->is<sf::Event::Closed>()) {
      window.close();
    } else if (event->is<sf::Event::KeyPressed>()) {
      if (auto keyEvent = event->getIf<sf::Event::KeyPressed>()) {
        if (keyEvent->code == sf::Keyboard::Key::Escape) {
          window.close();
        }
        if (gameOver && keyEvent->code == sf::Keyboard::Key::Enter) {
          gameOver = false;
          resetPlatforms();
          score = 0;
          player = Player();  // se reseteaza pozitia playerului si velocityul
          obstacle.deactivate();
        }
      }
    }
  }
}

void Game::update(float dt) {
  if (player.getPosition().y > 600) {
    gameOver = true;
    std::cout << "HIGHSCORE:" << highScore << std::endl;
    saveHighScore();
    return;
  }
  player.update(dt);
  if (obstacle.isActive()) {
    obstacle.update(dt);
  }
  sf::FloatRect playerBounds = player.getBounds();
  sf::Vector2f playerVelocity = player.getVelocity();

  // Check collision if player is moving down
  if (playerVelocity.y > 0) {
    for (auto& platform : platformPool.busyPlatforms) {
      sf::FloatRect platformBounds = platform->getBounds();

      if (playerBounds.findIntersection(platformBounds).has_value()) {
        // Check if player's bottom is touching the platform

        float playerBottom = playerBounds.position.y + playerBounds.size.y;
        float platformTop = platformBounds.position.y;

        float landingTolerance = 5.0f;  // marj

        if (playerBottom >= platformTop &&
            playerBottom <= platformTop + landingTolerance) {
          player.jump(NORMAL_V);
          break;  // Exit after the first valid collision
        }
      }
    }

		//trambulina
		sf::FloatRect platformBounds = bouncer.getBounds();
		if (checkCollision(player, bouncer)) {
			// Check if player's bottom is touching the platform

			float playerBottom = playerBounds.position.y + playerBounds.size.y;
			float platformTop = platformBounds.position.y;

			float landingTolerance = 5.0f;  

			if (playerBottom >= platformTop &&
					playerBottom <= platformTop + landingTolerance) {
				player.jump(BOUNCE_V);
			}
  	}
	}
  if (player.getPosition().y < 240) {
    float diff = 240 - player.getPosition().y;
    player.move(0, diff);
    for (auto& platform : platformPool.busyPlatforms) {
      platform->move(0, diff);
    }
		bouncer.move(0, diff);
    if (obstacle.isActive()) {
      obstacle.move(0, diff);
    }
  }

  // lirili larila
  if (obstacle.isActive()) {
    if (obstacle.shouldRemove()) {
      obstacle.deactivate();
    }
    if (checkCollision(player, obstacle)) {
      gameOver = 1;
      saveHighScore();
    }
  }
  if (score % 25 == 0 && score != 0) {
    obstacle.activate();
  }

  // reciclarea platformelor
  //std::vector<Platform<sf::RectangleShape>*> platformsToRecycle;
  bool bouncerNeedsRecycle = false;
	for (auto& platform : platformPool.busyPlatforms) {
    if (platform->getPosition().y > 600) {
      platform->scored = false;
      //platformsToRecycle.push_back(&platform);
    	platformPool.recPlatform(platform);
		}
  }
	if(bouncer.getPosition().y > 600) {
		bouncer.scored = false;
		bouncerNeedsRecycle = true;
	}

  // Reposition them above the current highest platform
  float highestY = 600.f;
  for (const auto& p : platformPool.busyPlatforms) {
    if (p->getPosition().y < highestY) {
      highestY = p->getPosition().y;
    }
  }

	if(bouncer.getPosition().y < highestY) {
		highestY = bouncer.getPosition().y;
	}

  for (auto& platform : platformPool.availablePlatforms) {
   	if(platform != NULL){
			auto tempPlatform = platformPool.getPlatform();
			tempPlatform->setPosition(rand() % 340, highestY - 100);
			highestY -= 100;  // Update for next platform
		}
	}
	
	if(bouncerNeedsRecycle) bouncer.setPosition(rand() % 340, highestY - 100);

  // keeping the score
  for (auto& platform : platformPool.busyPlatforms) {
    if (platform->getPosition().y > player.getPosition().y && !platform->scored) {
      score++;
      platform->scored = true;
    }
  }
	if (bouncer.getPosition().y > player.getPosition().y && !bouncer.scored) {
      score++;
     	bouncer.scored = true;
	}



  scoreText.setString("Score: " + std::to_string(score));
}



void Game::render() {
  window.clear(sf::Color::White);
  if (gameOver) {  // afisare meniu
    window.draw(highScoreText);
    window.draw(menuText);
  } else {  // afisare joc in desfasurare
    for (auto& platform : platformPool.busyPlatforms) {
      platform->draw(window);
    }
		bouncer.draw(window);
    if (obstacle.isActive()) {
      obstacle.draw(window);
    }
    player.draw(window);

    window.draw(scoreText);
  }
  window.display();
}

void Game::resetPlatforms() {
 	platformPool.clear();

	int x;
	int y;
  for (int i = 0; i < platformCount; i++) {
   	x = rand() % 340;
   	y = i * 90;
    std::cout << "COORDONATE PLATFORMA: " << x << " " << y << std::endl;
    auto platform = platformPool.getPlatform();
		platform->setPosition(x, y);
  }
	x = rand() % 340;
	y = platformCount * 90;
	bouncer.setPosition(x, y);
}

void Game::loadHighScore() {
  const std::string filename = "highscore.txt";

  try {
    std::ifstream file(filename);
    if (!file.good()) {
      throw HighScoreException(HighScoreException::ErrorType::FileNotFound,
                               filename);
    }

    int score;
    if (!(file >> score)) {
      throw HighScoreException(HighScoreException::ErrorType::InvalidFormat,
                               filename);
    }

    if (score < 0 ||
        score > 99999) {  // verifica daca scorul este posibil is plauzibil
      throw HighScoreException(HighScoreException::ErrorType::CorruptData,
                               filename, score);
    }

    highScore = score;
  } catch (const HighScoreException& e) {
    std::cerr << "HIGH SCORE ERROR: " << e.what() << "\n";
    e.createDefaultFile();
    highScore = 0;
  }
}

void Game::saveHighScore() {
  if (score > highScore) {
    highScore = score;
    highScoreText.setString("High Score: " + std::to_string(highScore));
    std::ofstream fileout("highscore.txt");
    fileout << highScore;
    fileout.close();
  }
}

