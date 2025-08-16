#include <doctest/doctest.h>
#include "map.hpp"

using namespace tiledpp::map;

TEST_CASE("JsonMap") {
    std::stringstream raw(
        R"({})" // Empty
    );

    CHECK_NOTHROW({
        JsonMap map = JsonMap(raw);
    });
}

TEST_CASE("getWidth") {
    std::stringstream raw(
        R"({
            "width": 11
        })"
    );

    JsonMap map(raw);

    CHECK_EQ(11, map.getWidth());
}

TEST_CASE("getHeight") {
    std::stringstream raw(
        R"({
            "height": 17
        })"
    );

    JsonMap map(raw);

    CHECK_EQ(17, map.getHeight());
}

TEST_CASE("getTileWidth") {
    std::stringstream raw(
        R"({
            "tilewidth": 23
        })"
    );

    JsonMap map(raw);

    CHECK_EQ(23, map.getTileWidth());
}

TEST_CASE("getTileHeight") {
    std::stringstream raw(
        R"({
            "tileheight": 71
        })"
    );

    JsonMap map(raw);

    CHECK_EQ(71, map.getTileHeight());
}

TEST_CASE("getOrientation") {
    
    SUBCASE("Orthogonal") {
        std::stringstream raw(
            R"({
                "orientation": "orthogonal"
            })"
        );

        JsonMap map(raw);

        CHECK_EQ(Orientation::Orthogonal, map.getOrientation());
    }

    SUBCASE("Isometric") {
        std::stringstream raw(
            R"({
                "orientation": "isometric"
            })"
        );

        JsonMap map(raw);

        CHECK_EQ(Orientation::Isometric, map.getOrientation());
    }

    SUBCASE("Staggered") {
        std::stringstream raw(
            R"({
                "orientation": "staggered"
            })"
        );

        JsonMap map(raw);

        CHECK_EQ(Orientation::Staggered, map.getOrientation());
    }

    SUBCASE("Hexagonal") {
        std::stringstream raw(
            R"({
                "orientation": "hexagonal"
            })"
        );

        JsonMap map(raw);

        CHECK_EQ(Orientation::Hexagonal, map.getOrientation());
    }
}

TEST_CASE("isInfinite") {

    SUBCASE("Map IS infinite") {
        std::stringstream raw(
            R"({
                "infinite": true
            })"
        );

        JsonMap map(raw);

        CHECK(map.isInfinite());
    }

    SUBCASE("Map IS NOT infinite") {
        std::stringstream raw(
            R"({
                "infinite": false
            })"
        );

        JsonMap map(raw);

        CHECK_FALSE(map.isInfinite());   
    }
}

TEST_CASE("getTilesets") {
    // TODO
}

TEST_CASE("getLayers") {
    std::stringstream raw(
        R"({
            "layers": [
                {},
                {},
                {},
                {},
                {}
            ]
        })"
    );

    JsonMap map(raw);

    CHECK_NOTHROW({
        map.getLayers();
    });


    auto layers = map.getLayers();
    CHECK_EQ(5, layers.size());
}