CC      := gcc
CFLAGS  := -std=c11 -Wall -Wextra -Werror -pedantic -O2
TARGET  := intstack

SRC     := src/stack.c src/main.c
OBJ     := $(SRC:.c=.o)

.PHONY: all run clean valgrind

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $@

src/%.o: src/%.c
	$(CC) $(CFLAGS) -Iinclude/ -c $< -o $@

run: $(TARGET)
	./$(TARGET)

valgrind: $(TARGET)
	valgrind --leak-check=full --show-leak-kinds=all ./$(TARGET)

clean:
	rm -f $(OBJ) $(TARGET)

