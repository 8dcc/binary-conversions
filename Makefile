
CC=gcc
CFLAGS=-Wall
BIN=conversor

all: $(BIN).out

$(BIN).out: src/*.c src/*.h
	$(CC) $(CFLAGS) -o $@ src/main.c

run: $(BIN).out
	./$<

clean:
	rm $(BIN).out
