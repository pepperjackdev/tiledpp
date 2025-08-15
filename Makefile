
.SILENT:

rat: run-all-tests

crat: clean run-all-tests

run-all-tests: build-for-tests
	./build/tests/tests

bft: build-for-tests

build-for-tests: build
	cmake --build build --target tests

b: build

build:
	cmake -B build -G Ninja

c: clean

clean:
	rm -rf build