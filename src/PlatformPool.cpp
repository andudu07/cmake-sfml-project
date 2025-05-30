#include "PlatformPool.h"

PlatformPool::PlatformPool(size_t initialSize) {
	for (size_t i = 0; i < initialSize; ++i) {
		availablePlatforms.push_back(std::make_shared<Platform<sf::RectangleShape>>(0, 0));
  }
}



std::shared_ptr<Platform<sf::RectangleShape>> PlatformPool::getPlatform() {
    if (availablePlatforms.empty()) {
        throw std::runtime_error("Nu exista platforme disponibile");
    }

    auto platform = availablePlatforms.back();
    availablePlatforms.pop_back();
    busyPlatforms.push_back(platform);
    return platform;
}

void PlatformPool::clear(){
	busyPlatforms.clear();
	availablePlatforms.clear();
}

void PlatformPool::recPlatform(std::shared_ptr<Platform<sf::RectangleShape>> platform) {
	auto it = std::find(busyPlatforms.begin(), busyPlatforms.end(), platform);
 	if (it != busyPlatforms.end()) {
 		busyPlatforms.erase(it);
    availablePlatforms.push_back(platform);
  }
}
