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
        virtual std::vector<tileset::Tileset> getTilesets() const = 0;
        virtual std::vector<layer::Layer> getLayers() const = 0;
};

}