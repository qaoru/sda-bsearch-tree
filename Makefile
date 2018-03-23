CC = gcc
CFLAGS = -g -Wall -Wextra -Werror

main:
	$(CC) main.c -o main $(CFLAGS)

clean:
	rm -rf main
