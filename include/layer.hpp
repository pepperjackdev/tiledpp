#pragma once

#include <list>
#include <string>

namespace tiledpp::map::layer {

class Layer {
    public:
        virtual ~Layer() = default;
        virtual int getId() const = 0;
        virtual std::string getName() const = 0;
        virtual int getWidth() const = 0;
        virtual int getHeight() const = 0;
};

}