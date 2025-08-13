cmake_minimum_required(VERSION 3.15)
project(tiledpp VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

file (GLOB SRC_FILES
    "src/*.cpp"
    "src/**/*.cpp"
)

add_library(tiledpp ${SRC_FILES})

target_include_directories(tiledpp
    PUBLIC
        ${CMAKE_SOURCE_DIR}/include
)

find_package(PkgConfig REQUIRED)
pkg_check_modules(deps REQUIRED IMPORTED_TARGET nlohmann_json)
target_link_libraries(tiledpp
    PRIVATE
        PkgConfig::deps
)

# Handling tests
option(ENABLE_TESTS "Build tests" ON)
if(ENABLE_TESTS)
    enable_testing()
    add_subdirectory(tests)
endif()
