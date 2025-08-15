#include <doctest/doctest.h>
#include <map.hpp>

using namespace tiledpp::map;

TEST_CASE("Construct JsonMap from fstream") {
    std::stringstream raw(
        R"({})" // Empty
    );

    CHECK_NOTHROW({
        JsonMap map = JsonMap(raw);
    });
}

TEST_CASE("Get map width") {
    std::stringstream raw(
        R"({
            "width": 11
        })"
    );

    JsonMap map(raw);

    CHECK_EQ(11, map.getWidth());
}

TEST_CASE("Get map height") {
    std::stringstream raw(
        R"({
            "height": 17
        })"
    );

    JsonMap map(raw);

    CHECK_EQ(17, map.getHeight());
}

TEST_CASE("Get map tiles width") {
    std::stringstream raw(
        R"({
            "tilewidth": 23
        })"
    );

    JsonMap map(raw);

    CHECK_EQ(23, map.getTileWidth());
}

TEST_CASE("Get map tiles height") {
    std::stringstream raw(
        R"({
            "tileheight": 71
        })"
    );

    JsonMap map(raw);

    CHECK_EQ(71, map.getTileHeight());
}

TEST_CASE("Get map orientation") {
    
    SUBCASE("Orthogonal orientation") {
        std::stringstream raw(
            R"({
                "orientation": "orthogonal"
            })"
        );

        JsonMap map(raw);

        CHECK_EQ(Orientation::Orthogonal, map.getOrientation());
    }

    SUBCASE("Isometric orientation") {
        std::stringstream raw(
            R"({
                "orientation": "isometric"
            })"
        );

        JsonMap map(raw);

        CHECK_EQ(Orientation::Isometric, map.getOrientation());
    }

    SUBCASE("Staggered orientation") {
        std::stringstream raw(
            R"({
                "orientation": "staggered"
            })"
        );

        JsonMap map(raw);

        CHECK_EQ(Orientation::Staggered, map.getOrientation());
    }

    SUBCASE("Hexagonal orientation") {
        std::stringstream raw(
            R"({
                "orientation": "hexagonal"
            })"
        );

        JsonMap map(raw);

        CHECK_EQ(Orientation::Hexagonal, map.getOrientation());
    }
}

TEST_CASE("Is map infinite") {

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

TEST_CASE("Get map tilesets") {
    // TODO
}

TEST_CASE("Get map layers") {
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