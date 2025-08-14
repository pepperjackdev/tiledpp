#pragma once

#include <list>
#include <string>

namespace tiledpp::map::tileset {
    
class Tileset {
    public:
        virtual ~Tileset() = default;
        virtual int getTileWidth() const = 0;
        virtual int getTileHeight() const = 0;
        virtual int getFirstGlobalId() const = 0;
        virtual std::string getSourcePath() const = 0;
};

}