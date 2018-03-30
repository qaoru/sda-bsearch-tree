CC = gcc
CFLAGS = -g -Wall -Wextra -Werror
DEP = orderedSet.c binary_tree.c

main: main.o orderedSet.o binary_tree.o
	$(CC) $(CFLAGS) -o $@ $^

main.o: main.c binary_tree.h orderedSet.h
	$(CC) $(CFLGAS) -o main.o -c main.c

binary_tree.o: binary_tree.c binary_tree.h orderedSet.h
	$(CC) $(CFLGAS) -o binary_tree.o -c binary_tree.c

orderedSet.o: orderedSet.c orderedSet.h
	$(CC) $(CFLGAS) -o orderedSet.o -c orderedSet.c

clean:
	rm -rf main *.o
