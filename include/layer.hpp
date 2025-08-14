#pragma once

#include <list>
#include <string>
#include <istream>

#include <nlohmann/json.hpp>

namespace tiledpp::map::layer {

class Layer {
    public:
        virtual ~Layer() = default;
        virtual int getId() const = 0;
        virtual std::string getName() const = 0;
        virtual int getWidth() const = 0;
        virtual int getHeight() const = 0;
};

class JsonLayer: public Layer {
    private:
        nlohmann::json layerJson;

    public:
        JsonLayer(nlohmann::json layerJson);
        JsonLayer(std::istream &layerJson);
        int getId() const override;
        std::string getName() const override;
        int getWidth() const override;
        int getHeight() const override;  
};

}