#include <istream>
#include <list>

#include "layer.hpp"

using namespace tiledpp::map::layer;
using json = nlohmann::json;

JsonLayer::JsonLayer(json layerJson) {
    this->layerJson=layerJson;
}

JsonLayer::JsonLayer(std::istream &layerJsonStream) {
    this->layerJson = json::parse(layerJsonStream);
}

int JsonLayer::getId() const {
    return this->layerJson["id"];
}

std::string JsonLayer::getName() const {
    return this->layerJson["name"];
}

int JsonLayer::getWidth() const {
    return this->layerJson["width"];
}

int JsonLayer::getHeight() const {
    return this->layerJson["height"];
}