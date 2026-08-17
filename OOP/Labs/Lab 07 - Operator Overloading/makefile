all: build test

build:
ifdef TEST
	cmake -Bbuild
	cmake --build build --target $(TEST)
else
	cmake -Bbuild
	cmake --build build
endif

test: build
ifdef TEST
	ctest --test-dir build -VV --progress --output-on-failure -R $(TEST)
else
	ctest --test-dir build -VV --progress --output-on-failure
endif

clean:
	rm -rf build
