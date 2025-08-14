run-all-tests: build-for-tests
	ctest --test-dir build --output-on-failure

build-for-tests: build
	cmake --build build --target tests

build:
	cmake -B build