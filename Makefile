CPP = g++
CPPFLAGS = -ggdb -o
CC = $(CPP) $(CPPFLAGS)

all: 1-1

1-1: 1-1.cpp
	$(CC) 1-1 1-1.cpp

clean:
	rm -f 1-1