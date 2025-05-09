/*#pragma once
#include <SFML/Graphics.hpp>

class Obstacle {
public:
   	Obstacle();
	 	void update(float dt);
    void draw(sf::RenderWindow& window) const;
    sf::FloatRect getBounds() const;
    bool shouldRemove() const;
    bool getDirection() const;
		bool isActive() const;
		void activate();
		void deactivate();
		void move(float dx, float dy);
		void changeDirection();
		sf::Vector2f getPosition() const;
private:
		bool active = 0;
		bool direction = 1;
		sf::Texture tex;
		sf::Sprite sprite;
    const float speed = 150.f;
		sf::Vector2f start_pos = {0, -100};
};
*/
#pragma once
#include <SFML/Graphics.hpp>

class Obstacle {
 public:
  Obstacle();
  void update(float dt);
  void draw(sf::RenderWindow& window) const;
  sf::FloatRect getBounds() const;
  bool shouldRemove() const;
  bool getDirection() const;
  bool isActive() const;
  void activate();
  void deactivate();
  void move(float dx, float dy);
  void changeDirection();
  sf::Vector2f getPosition() const;

 private:
  bool active = 0;
  bool direction = 1;
  sf::Texture tex;
  sf::Sprite sprite;
  const float speed = 150.f;
  sf::Vector2f start_pos = {0, -100};
};

