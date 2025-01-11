CC = g++
CFLAGS = -Wall

SOURCES = sort.c time.c
OBJECTS = $(SOURCES:.c=.o)

all: sort

sort: $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -f $(OBJECTS) sort
