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
        //virtual int getRows() const = 0;
        virtual int getTileWidth() const = 0;
        virtual int getTileHeight() const = 0;
        virtual int getSpacing() const = 0;
        virtual int getMargin() const = 0;
        virtual int getTileCount() const = 0;
        virtual int getFirstGlobalId() const = 0;
        virtual std::string getSourcePath() const = 0;
        //virtual std::vector<std::unique_ptr<tileset::tile::Tile>> getTiles() const = 0;
};

class JsonTileset: public Tileset {
    private:
        nlohmann::json tilesetJson;

    public:
        JsonTileset(nlohmann::json tilesetJson);
        JsonTileset(std::istream &tilesetJsonStream);
        std::string getName() const override;
        int getColumns() const override;
        //int getRows() const override;
        int getTileWidth() const override;
        int getTileHeight() const override;
        int getSpacing() const override;
        int getMargin() const override;
        int getTileCount() const override;
        int getFirstGlobalId() const override;
        std::string getSourcePath() const override;
        //std::vector<std::unique_ptr<tileset::tile::Tile>> getTiles() const override;
};

}