CPP = g++
CPPFLAGS = -ggdb
BIN = $(CPP) $(CPPFLAGS) $^ -o $@

ALL = 1-1-1 1-1-2 

all: $(ALL)

1-1-1: 1-1-1.cpp
	$(BIN)

1-1-2: 1-1-2.cpp
	$(BIN)

clean:
	rm -f $(ALL)