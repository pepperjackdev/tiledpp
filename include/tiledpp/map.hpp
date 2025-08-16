#pragma once

#include <vector>
#include <string>
#include <istream>

#include "layer.hpp"
#include "tileset.hpp"

#include <nlohmann/json.hpp>

#define ORIENTATION_ORTOGONAL_STR "orthogonal"
#define ORIENTATION_ISOMETRIC_STR "isometric"
#define ORIENTATION_STAGGERED_STR "staggered"
#define ORIENTATION_HEXAGONAL_STR "hexagonal"

namespace tiledpp::map {

enum class Orientation {
    Orthogonal,
    Isometric,
    Staggered,
    Hexagonal
};

class Map {
    public:
        virtual ~Map() = default;
        virtual int getWidth() const = 0;
        virtual int getHeight() const = 0;
        virtual int getTileWidth() const = 0;
        virtual int getTileHeight() const = 0;
        virtual Orientation getOrientation() const = 0;
        virtual bool isInfinite() const = 0;
        //virtual std::vector<std::unique_ptr<tileset::Tileset>> getTilesets() const = 0;
        virtual std::vector<std::unique_ptr<layer::Layer>> getLayers() const = 0;
};

class JsonMap: public Map {
    private:
        nlohmann::json mapJson;

    public:
        JsonMap(std::istream &json);
        int getWidth() const;
        int getHeight() const;
        int getTileWidth() const;
        int getTileHeight() const;
        Orientation getOrientation() const;
        bool isInfinite() const;
        //std::vector<std::unique_ptr<tileset::Tileset>> getTilesets() const;
        std::vector<std::unique_ptr<layer::Layer>> getLayers() const;
};

}