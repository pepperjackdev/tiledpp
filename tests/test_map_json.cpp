#include <doctest/doctest.h>
#include <map.hpp>

using namespace tiledpp::map;

TEST_CASE("Construct JsonMap from fstream") {
    std::stringstream raw(
        R"({})" // Empty
    );

    CHECK_NOTHROW({
        JsonMap _(raw);
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