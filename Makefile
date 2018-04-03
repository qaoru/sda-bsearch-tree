CC = gcc -g
CFLAGS = -Wall -Wextra -Werror
DEP = orderedSet.c binary_tree.c

main: main.o orderedSet.o binary_tree.o utils.o treeGeneration.o
	$(CC) $(CFLAGS) -o $@ $^

main.o: main.c binary_tree.h
	$(CC) $(CFLGAS) -o main.o -c main.c

binary_tree.o: binary_tree.c binary_tree.h orderedSet.h
	$(CC) $(CFLGAS) -o binary_tree.o -c binary_tree.c

orderedSet.o: orderedSet.c orderedSet.h utils.h
	$(CC) $(CFLGAS) -o orderedSet.o -c orderedSet.c

utils.o: utils.c utils.h
	$(CC) $(CFLAGS) -o utils.o -c utils.c

treeGeneration.o: treeGeneration.c treeGeneration.h binary_tree.h
	$(CC) $(CFLAGS) -o treeGeneration.o -c treeGeneration.c

clean:
	rm -rf main *.o
