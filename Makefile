CC = gcc -g
CFLAGS = -Wall -Wextra -Werror

BIN = main
SRC = $(wildcard src/*.c)
OBJ = $(patsubst src/%.c, obj/%.o,$(SRC))

$(shell mkdir -p obj)

$(BIN) : $(OBJ)
	$(CC) -o $@ $^


$(OBJ) : obj/%.o : src/%.c
	$(CC) $(CFLAGS) -c $^ -o $@ -Iinclude

clean:
	rm -rf obj

clean_all: clean
	rm main