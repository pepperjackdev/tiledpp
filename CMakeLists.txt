cmake_minimum_required(VERSION 3.15)
project(tiledpp VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

file(GLOB SRC_FILES
    "src/*.cpp"
    "src/**/*.cpp"
)

add_library(tiledpp ${SRC_FILES})

target_include_directories(tiledpp
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
)

find_package(PkgConfig REQUIRED)
pkg_check_modules(deps REQUIRED IMPORTED_TARGET nlohmann_json)
target_link_libraries(tiledpp PRIVATE PkgConfig::deps)

include(GNUInstallDirs)

install(TARGETS tiledpp
    EXPORT tiledppTargets
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    INCLUDES DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)

install(DIRECTORY include/ DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

install(EXPORT tiledppTargets
    FILE tiledppTargets.cmake
    NAMESPACE tiledpp::
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/tiledpp
)

include(CMakePackageConfigHelpers)
write_basic_package_version_file(
    "${CMAKE_CURRENT_BINARY_DIR}/tiledppConfigVersion.cmake"
    VERSION ${PROJECT_VERSION}
    COMPATIBILITY SameMajorVersion
)

configure_file(
    ${CMAKE_CURRENT_LIST_DIR}/cmake/tiledppConfig.cmake.in
    ${CMAKE_CURRENT_BINARY_DIR}/tiledppConfig.cmake
    @ONLY
)

install(FILES
    "${CMAKE_CURRENT_BINARY_DIR}/tiledppConfig.cmake"
    "${CMAKE_CURRENT_BINARY_DIR}/tiledppConfigVersion.cmake"
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/tiledpp
)

option(ENABLE_TESTS "Build tests" ON)
if(ENABLE_TESTS)
    enable_testing()
    add_subdirectory(tests)
endif()
