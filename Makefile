CFLAGS=-g -Wall -O3 -std=c99

all:
	gcc test.c -o makecross $(CFLAGS)

clean: makecross
	rm -rf makecross makecross.dSYM
