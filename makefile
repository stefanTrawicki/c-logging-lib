CC=clang
CFLAGS=-g -Wall
BINS=liblogging.so

all: clean $(BINS)

liblogging.so: src/liblogging.c
	$(CC) $(CFLAGS) src/liblogging.c -shared -fPIC -o liblogging.so
	cp liblogging.h /usr/local/include
	cp liblogging.so /usr/local/lib

clean:
	rm -rf *.dSYM $(BINS)