#pragma once

#include <vector>
#include <string>
#include <istream>

#include "layer.hpp"
#include "tileset.hpp"

#include <nlohmann/json.hpp>

namespace tiledpp::map {

class Map {
    public:
        virtual ~Map() = default;
        virtual int getWidth() const = 0;
        virtual int getHeight() const = 0;
        virtual std::vector<std::unique_ptr<layer::Layer>> getLayers() const = 0;
        //virtual std::vector<tileset::Tileset> getTilesets() const = 0;
};

class JsonMap: public Map {
    private:
        nlohmann::json mapJson;

    public:
        JsonMap(std::istream &json);
        int getWidth() const override;
        int getHeight() const override;
        std::vector<std::unique_ptr<layer::Layer>> getLayers() const override;
        //std::vector<tileset::Tileset> getTilesets() const override;
};

}