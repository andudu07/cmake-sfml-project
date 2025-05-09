#include <SFML/Graphics.hpp>
#pragma once
#include "Exceptions.h"
class Character {
	public:
//		Character();
		virtual ~Character() = default;
		void draw(sf::RenderWindow& window) const {
			window.draw(sprite);	
		}
		virtual void update(float dt) = 0;
		void move(float dx, float dy) { sprite.move({dx, dy}); }
		virtual sf::FloatRect getBounds() const { return sprite.getGlobalBounds(); }
		sf::Vector2f getPosition() const { return sprite.getPosition(); }
		sf::Vector2f getVelocity() const { return velocity; }
	
	protected:
		Character() : tex(std::make_shared<sf::Texture>()), sprite(*tex){}
		std::shared_ptr<sf::Texture> tex;
		sf::Sprite sprite;
		sf::Vector2f velocity;
		sf::Vector2f start_pos;
		void loadTexture(const std::string& filename) {
    		try {
        auto newTex = std::make_shared<sf::Texture>();
        
        if (!newTex->loadFromFile(filename)) {
            throw TextureLoadException(filename, "File found but invalid format");
        }
        
        tex = newTex;
        sprite.setTexture(*tex, true);
        
    } catch (const std::exception& e) {
        throw TextureLoadException(filename, e.what());
    }
		}
};

