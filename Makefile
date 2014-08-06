CPP = g++
CPPFLAGS = -std=c++11 -ggdb
BIN = $(CPP) $(CPPFLAGS) $^ -o $@

ALL = bin/1.1.1 \
      bin/1.1.2 \
      bin/1.2   \
      bin/1.3   \
      bin/1.4   \
      bin/1.5   \
      bin/1.6   \
      bin/1.7   \
      bin/1.8

all: $(ALL)

bin/%: src/%.cpp
	$(BIN)

clean:
	rm -f $(ALL)