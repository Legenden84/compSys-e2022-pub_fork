CC=gcc
CFLAGS=-Wall -Wextra -pedantic
PROGRAMS=ex1

all: $(PROGRAMS)

%: %.c
	$(CC) -o $@ $^ $(CFLAGS)

clean:
	rm -f $(PROGRAMS)