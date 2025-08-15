#include <doctest/doctest.h>
#include <layer.hpp>

using namespace tiledpp::map::layer;

TEST_CASE("JsonLayer") {
    std::stringstream raw(
        R"({})" // Empty
    );

    CHECK_NOTHROW({
        JsonLayer layer(raw);
    });
}

TEST_CASE("getId") {
    std::stringstream raw(R"({
        "id": 11    
    })");

    JsonLayer layer(raw);

    CHECK_EQ(11, layer.getId());
}

TEST_CASE("getName") {
    std::stringstream raw(R"({
        "name": "layername"    
    })");

    JsonLayer layer(raw);

    CHECK_EQ("layername", layer.getName());
}

TEST_CASE("getWidth") {
    std::stringstream raw(R"({
        "width": 23    
    })");

    JsonLayer layer(raw);

    CHECK_EQ(23, layer.getWidth());
}

TEST_CASE("getHeight") {
    std::stringstream raw(R"({
        "height": 29    
    })");

    JsonLayer layer(raw);

    CHECK_EQ(29, layer.getHeight());
}