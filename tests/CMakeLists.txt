find_package(doctest REQUIRED)

file(GLOB TEST_SRC CONFIGURE_DEPENDS *.cpp)

add_executable(tests ${TEST_SRC})
target_link_libraries(tests PRIVATE tiledpp doctest::doctest)

add_test(NAME tests COMMAND tests)
