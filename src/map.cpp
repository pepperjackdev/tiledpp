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

std::vector<std::unique_ptr<layer::Layer>> JsonMap::getLayers() const {
    std::vector<std::unique_ptr<layer::Layer>> layers = {};
    for (json layerJson: this->mapJson["layers"]) {
        layers.push_back(std::make_unique<layer::JsonLayer>(
            layer::JsonLayer(layerJson)
        ));
    }
    return layers;
}