#pragma once

#include <list>
#include <string>
#include <fstream>

#include "layer.hpp"
#include "tileset.hpp"

#include <nlohmann/json.hpp>

using json = nlohmann::json;

namespace tiledpp::map {

class Map;

class Map {
    public:
        virtual ~Map() = default;
        virtual int getWidth() const = 0;
        virtual int getHeight() const = 0;
        virtual std::list<layer::Layer> getLayers() const = 0;
        virtual std::list<tileset::Tileset> getTilesets() const = 0;
};

class JsonMap: public Map {
    private:
        json source;

    public:
        JsonMap(std::istream &source);
        int getWidth() const override;
        int getHeight() const override;
        std::list<layer::Layer> getLayers() const override;
        std::list<tileset::Tileset> getTilesets() const override;
};

}