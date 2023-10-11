CC=gcc

all: sort

sort: src/sort.c src/sort.h src/main.c
	$(CC) -o bin/sort src/sort.c src/sort.h src/main.c

clean:
	rm bin/*