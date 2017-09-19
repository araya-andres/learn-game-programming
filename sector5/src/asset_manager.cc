#include "asset_manager.h"
#include <map>
#include <stdexcept>

sf::Texture& AssetManager::getTexture(const std::string& filename)
{
    static std::map<std::string, sf::Texture> textures;
    auto it = textures.find(filename);
    if (it != textures.end()) {
        return it->second;
    }
    auto& texture = textures[filename];
    if (!texture.loadFromFile(filename)) {
        throw std::runtime_error{""};
    }
    return texture;
}
