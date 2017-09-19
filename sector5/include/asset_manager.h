#ifndef ASSET_MANAGER_H
#define ASSET_MANAGER_H

#include <string>
#include <SFML/Graphics.hpp>

namespace AssetManager
{
    sf::Texture& getTexture(const std::string& filename);
}

#endif
