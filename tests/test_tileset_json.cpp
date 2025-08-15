#include <doctest/doctest.h>

#include "tileset.hpp"

using namespace tiledpp::map::tileset;

TEST_CASE("JsonTileset") {
    std::stringstream raw(R"({})");

    SUBCASE("JsonTileset(istream)") {
        CHECK_NOTHROW({
            JsonTileset _(raw);
        });
    }

    SUBCASE("JsonTileset(json)") {
        CHECK_NOTHROW({
            JsonTileset _(nlohmann::json::parse(raw));
        });
    }
}

TEST_CASE("getName") {
    std::stringstream raw(R"({
        "name": "mytesttilesetname"
    })");

    JsonTileset tileset(raw);

    CHECK_EQ("mytesttilesetname", tileset.getName());
}

TEST_CASE("getColumns") {
    std::stringstream raw(R"({
        "columns": 19
    })");

    JsonTileset tileset(raw);

    CHECK_EQ(19, tileset.getColumns());
}

TEST_CASE("getTileWidth") {
    std::stringstream raw(R"({
        "tilewidth": 331    
    })");

    JsonTileset tileset(raw);

    CHECK_EQ(331, tileset.getTileWidth());
}


TEST_CASE("getTileHeight") {
    std::stringstream raw(R"({
        "tileheight": 793    
    })");

    JsonTileset tileset(raw);

    CHECK_EQ(793, tileset.getTileHeight());
}

TEST_CASE("getSpacing") {
    std::stringstream raw(R"({
        "spacing": 1    
    })");

    JsonTileset tileset(raw);

    CHECK_EQ(1, tileset.getSpacing());
}


TEST_CASE("getMargin") {
    std::stringstream raw(R"({
        "margin": 3    
    })");

    JsonTileset tileset(raw);

    CHECK_EQ(3, tileset.getMargin());
}

TEST_CASE("getTileCount") {
    std::stringstream raw(R"({
        "tilecount": 17    
    })");

    JsonTileset tileset(raw);

    CHECK_EQ(17, tileset.getTileCount());
}

TEST_CASE("getSourcePath") {
    std::stringstream raw(R"({
        "source": "mytilesetimage.png"    
    })");

    JsonTileset tileset(raw);

    CHECK_EQ("mytilesetimage.png", tileset.getSourcePath());
}

TEST_CASE("getFirstGlobalId") {
    std::stringstream raw(R"({
        "firstgid": 931    
    })");

    JsonTileset tileset(raw);

    CHECK_EQ(931, tileset.getFirstGlobalId());   
}