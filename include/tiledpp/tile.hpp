#pragma once

#include <list>
#include <string>

namespace tiledpp::map::tileset::tile {

class Tile {
    public:
        virtual int getId() const = 0;
        virtual int getWidth() const = 0;
        virtual int getHeight() const = 0;
        virtual int getX() const = 0;
        virtual int getY() const = 0;
};

}