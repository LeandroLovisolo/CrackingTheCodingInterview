CPP = g++
CPPFLAGS = -ggdb
BIN = $(CPP) $(CPPFLAGS) $^ -o $@

ALL = 1-1-1 1-1-2 1-2 1-3 1-4

all: $(ALL)

1-1-1: 1-1-1.cpp
	$(BIN)

1-1-2: 1-1-2.cpp
	$(BIN)

1-2: 1-2.cpp
	$(BIN)

1-3: 1-3.cpp
	$(BIN)

1-4: 1-4.cpp
	$(BIN)

clean:
	rm -f $(ALL)