#include <fstream>
#include <list>

#include "map.hpp"
#include "layer.hpp"
#include "tileset.hpp"

using namespace tiledpp::map;
using json = nlohmann::json;

JsonMap::JsonMap(std::istream &json) {
    this->source = json::parse(json);
}

int JsonMap::getWidth() const {
    return (int)this->source["width"];
}

int JsonMap::getHeight() const {
    return 0;
}

std::list<layer::Layer> JsonMap::getLayers() const {
    
}

std::list<tileset::Tileset> JsonMap::getTilesets() const {
    
}