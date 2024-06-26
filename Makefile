SRC = main.c item.c modes.c
CFLAGS = -Wall -O3

all: main.c
	gcc -o wishsort $(SRC) $(CFLAGS)
	./wishsort

# Memory leak check
valgrind: main.c
	gcc -o wishsort $(SRC) -g -Og
	valgrind --leak-check=full -s ./wishsort
