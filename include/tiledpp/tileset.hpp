#pragma once

#include <list>
#include <string>
#include <istream>

#include "tile.hpp"

#include <nlohmann/json.hpp>

namespace tiledpp::map::tileset {
    
class Tileset {
    public:
        virtual ~Tileset() = default;
        virtual std::string getName() const = 0;
        virtual int getColumns() const = 0;
        virtual int getRows() const = 0;
        virtual int getTileWidth() const = 0;
        virtual int getTileHeight() const = 0;
        virtual int getSpacing() const = 0;
        virtual int getMargin() const = 0;
        virtual int getTileCount() const = 0;
        virtual int getFirstGlobalId() const = 0;
        virtual std::string getSourcePath() const = 0;
        virtual std::vector<tileset::tile::Tile> getTiles() const = 0;
};

}