CC := gcc
CFLAGS := -ggdb
LDFLAGS := `pkg-config --libs x11 xtst`

all: clean xtyper

clean:
	rm -f *.o xtyper

utils:
	${CC} ${CFLAGS} -c -o $@.o $@.c

xtyper: utils
	${CC} ${CFLAGS} ${LDFLAGS} -o $@ *.o $@.c


# vim:ft=make
#
