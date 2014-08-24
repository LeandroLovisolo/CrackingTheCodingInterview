CPP = g++
CPPFLAGS = -std=c++11 -ggdb
BIN = $(CPP) $(CPPFLAGS) $^ -o $@

ALL = $(patsubst src/%.cpp, bin/%, $(wildcard src/*.cpp))

.PHONY: clean
	
all: $(ALL)

bin/%: src/%.cpp
	$(BIN)

clean:
	rm -f $(ALL)
