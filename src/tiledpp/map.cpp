#include <fstream>
#include <list>

#include "map.hpp"
#include "layer.hpp"
#include "tileset.hpp"

using namespace tiledpp::map;
using json = nlohmann::json;

JsonMap::JsonMap(std::istream &mapJson) {
    this->mapJson = json::parse(mapJson);
}

int JsonMap::getWidth() const {
    return (int)this->mapJson["width"];
}

int JsonMap::getHeight() const {
    return (int)this->mapJson["height"];
}

int JsonMap::getTileWidth() const {
    return (int)this->mapJson["tilewidth"];
}

int JsonMap::getTileHeight() const {
    return (int)this->mapJson["tileheight"];
}

Orientation JsonMap::getOrientation() const {
    std::string orientationString = this->mapJson["orientation"];
    if (orientationString == ORIENTATION_ORTOGONAL_STR) {
        return Orientation::Orthogonal;
    } else if (orientationString == ORIENTATION_ISOMETRIC_STR) {
        return Orientation::Isometric;
    } else if (orientationString == ORIENTATION_STAGGERED_STR) {
        return Orientation::Staggered;
    } else if (orientationString == ORIENTATION_HEXAGONAL_STR) {
        return Orientation::Hexagonal;
    } else {
        // FIXME: provide custom error: Malformed
        throw std::invalid_argument( "Malformed data" );
    }
}

bool JsonMap::isInfinite() const {
    return this->mapJson["infinite"];
}

std::vector<std::unique_ptr<layer::Layer>> JsonMap::getLayers() const {
    std::vector<std::unique_ptr<layer::Layer>> layers = {};
    for (json layerJson: this->mapJson["layers"]) {
        layers.push_back(std::make_unique<layer::JsonLayer>(
            layer::JsonLayer(layerJson)
        ));
    }
    return layers;
}