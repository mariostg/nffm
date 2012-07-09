CC      = gcc
CFLAGS  = -g
LDFLAGS = -lncurses

SRC = nffm.c
HDR = nffm.h config.h
OBJ = $(SRC:.c=.o)

BIN = nffm

.PHONY: default all clean

default: all
all: $(BIN)

%.o: %.c $(HDR)
	$(CC) $(CFLAGS) -c $< -o $@

$(BIN): $(OBJ)
	$(CC) $(CFLAGS) $(LDFLAGS) $^ -o $@

clean:
	rm -rf $(BIN) $(OBJ)
