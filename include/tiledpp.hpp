#pragma once

#include <list>
#include <string>

namespace tiledpp {

class IMap;
class ILayer;
class ITileset;

class IMap {
    public:
        virtual ~IMap() = default;
        virtual int getWidth() const = 0;
        virtual int getHeight() const = 0;
        virtual std::list<ILayer> getLayers() const = 0;
        virtual std::list<ITileset> getTilesets() const = 0;
};

class ILayer {
    public:
        virtual ~ILayer() = default;
        virtual int getId() const = 0;
        virtual std::string getName() const = 0;
        virtual int getWidth() const = 0;
        virtual int getHeight() const = 0;
};

class ITileset {
    public:
        virtual ~ITileset() = default;
};

} // tiledpp