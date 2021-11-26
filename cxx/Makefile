build/run.x:build/Makefile $(wildcard src/*)
	cd build;make
build/Makefile:CMakeLists.txt
	cmake -S . -B build

.PHONY:clean
clean:
	rm -r build

.PHONY:run
run:build/run.x
	./build/run.x
