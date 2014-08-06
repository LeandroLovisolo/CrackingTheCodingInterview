CPP = g++
CPPFLAGS = -ggdb
BIN = $(CPP) $(CPPFLAGS) $^ -o $@

ALL = bin/1.1.1 \
      bin/1.1.2 \
      bin/1.2   \
      bin/1.3   \
      bin/1.4

all: $(ALL)

bin/%: src/%.cpp
	$(BIN)

clean:
	rm -f $(ALL)