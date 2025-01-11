CC = g++
CFLAGS = -Wall

SOURCES = time.cpp algo.cpp 
HEADERS= time.h
OBJECTS = $(SOURCES:.c=.o)

all: algo

algo: $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -f $(OBJECTS) algo
