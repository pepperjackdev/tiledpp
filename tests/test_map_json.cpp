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

