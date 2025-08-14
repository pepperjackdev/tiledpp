rat: run-all-tests

crat: clean run-all-tests

run-all-tests: build-for-tests
	ctest --test-dir build --output-on-failure

bft: build-for-tests

build-for-tests: build
	cmake --build build --target tests

b: build

build:
	cmake -B build

c: clean

clean:
	rm -rf build