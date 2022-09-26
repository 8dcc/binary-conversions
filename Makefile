
CC=gcc
CFLAGS=-Wall
BIN=conversor
LDLIBS=-lm

all: $(BIN).out

$(BIN).out: src/*.c src/*.h
	$(CC) $(CFLAGS) -o $@ src/main.c $(LDLIBS)

run: $(BIN).out
	./$<

clean:
	rm $(BIN).out
