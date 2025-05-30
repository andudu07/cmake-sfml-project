#pragma once
#include <vector>
#include <memory>
#include "Platform.h"

class PlatformPool {
public:
	PlatformPool(size_t initialSize);  
	void clear();
	std::shared_ptr<Platform<sf::RectangleShape>> getPlatform();  
	void recPlatform(std::shared_ptr<Platform<sf::RectangleShape>> platform);  
	std::vector<std::shared_ptr<Platform<sf::RectangleShape>>> busyPlatforms;
	std::vector<std::shared_ptr<Platform<sf::RectangleShape>>> availablePlatforms;
};
