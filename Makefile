CC      = gcc
CFLAGS  = -g
LDFLAGS = -lncurses

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
	$(CC) $(CFLAGS) $(LDFLAGS) $^ -o $@

clean:
	rm -rf $(BIN) $(OBJ)

install: all
	test -d ${DESTDIR}${BINDIR}  || mkdir -p ${DESTDIR}${BINDIR}
	install -m755 ${BIN}  ${DESTDIR}${BINDIR}/${BIN}
