CC = gcc
CFLAGS = -g -Wall -Wextra -Werror
DEP = orderedSet.c binary_tree.c

main:
	$(CC) main.c $(DEP) -o main $(CFLAGS)

clean:
	rm -rf main
