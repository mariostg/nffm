CC      = gcc
CFLAGS  = -g -std=gnu99
LDFLAGS = -lncurses -lz -ltar

SRC = nffm.c
HDR = nffm.h config.h
OBJ = $(SRC:.c=.o)

BIN = nffm

PREFIX?=/usr
BINDIR=${PREFIX}/bin

.PHONY: default all clean install

default: all
all: $(BIN)

%.o: %.c $(HDR)
	$(CC) $(CFLAGS) -c $< -o $@

$(BIN): $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS)

clean:
	rm -rf $(BIN) $(OBJ)

install: all
	test -d ${DESTDIR}${BINDIR}  || mkdir -p ${DESTDIR}${BINDIR}
	install -m755 ${BIN}  ${DESTDIR}${BINDIR}/${BIN}
