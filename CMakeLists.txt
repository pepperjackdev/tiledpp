cmake_minimum_required(VERSION 3.31)
project(tiledpp VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_EXTENSIONS OFF)

file(GLOB SRC_FILES 
    "src/**/*.cpp"
)
add_library(tiledpp ${SRC_FILES})

find_package(nlohmann_json CONFIG REQUIRED)

target_include_directories(tiledpp
    PUBLIC
    "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/tiledpp>"
    "$<INSTALL_INTERFACE:include/tiledpp>"
)

target_link_libraries(tiledpp PRIVATE nlohmann_json::nlohmann_json)

option(ENABLE_TESTS "Build tests" ON)
if(ENABLE_TESTS)
    enable_testing()
    add_subdirectory(tests)
endif()

include(GNUInstallDirs)

install(TARGETS tiledpp
        EXPORT tiledppTargets
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
        ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
        RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
        INCLUDES DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)

install(FILES tiledpp.hpp DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

install(EXPORT tiledppTargets
        FILE tiledppTargets.cmake
        NAMESPACE tiledpp::
        DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/tiledpp
)