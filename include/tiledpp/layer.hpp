#pragma once

#include <list>
#include <string>
#include <istream>

#include <nlohmann/json.hpp>

namespace tiledpp::map::layer {

enum class LayerType {
    TileLayer,
};

class Layer {
    public:
        virtual ~Layer() = default;
        virtual int getId() const = 0;
        virtual std::string getName() const = 0;
        virtual LayerType getLayerType() const = 0;
        virtual int getWidth() const = 0;
        virtual int getHeight() const = 0;
};

}