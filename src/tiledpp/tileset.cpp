#include <tileset.hpp>

#include <nlohmann/json.hpp>

using namespace tiledpp::map::tileset;
using json = nlohmann::json;

JsonTileset::JsonTileset(json tilesetJson) {
    this->tilesetJson = tilesetJson;
}

JsonTileset::JsonTileset(std::istream &tilesetJsonStream) {
    this->tilesetJson = json::parse(tilesetJsonStream);
}

std::string JsonTileset::getName() const {
    return this->tilesetJson["name"];
}

int JsonTileset::getColumns() const {
    return this->tilesetJson["columns"];
}

int JsonTileset::getTileWidth() const {
    return this->tilesetJson["tilewidth"];
}

int JsonTileset::getTileHeight() const {
    return this->tilesetJson["tileheight"];
}

int JsonTileset::getSpacing() const {
    return this->tilesetJson["spacing"];
}

int JsonTileset::getMargin() const {
    return this->tilesetJson["margin"];
}

int JsonTileset::getTileCount() const {
    return this->tilesetJson["tilecount"];
}

std::string JsonTileset::getSourcePath() const {
    return this->tilesetJson["source"];
}

int JsonTileset::getFirstGlobalId() const {
    return this->tilesetJson["firstgid"];
}