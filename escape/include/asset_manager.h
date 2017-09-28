#ifndef ASSET_MANAGER_H
#define ASSET_MANAGER_H

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <map>
#include <stdexcept>
#include <string>

namespace AssetManager
{
    template <typename T>
    T& get(const std::string& filename)
    {
        static std::map<std::string, T> assets;
        auto it = assets.find(filename);
        if (it != assets.end()) {
            return it->second;
        }
        auto& asset = assets[filename];
        if (!asset.loadFromFile(filename)) {
            throw std::runtime_error{"could not load file: " + filename};
        }
        return asset;
    }
}

#endif
