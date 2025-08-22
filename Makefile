CC = clang
CFLAGS = -Wall -Wextra -std=c17 -g -Iinclude
SRC = src/main.c src/screen.c src/entity.c src/object.c src/scene.c
OBJ = $(SRC:.c=.o)

all: game

game: $(OBJ)
	$(CC) $(CFLAGS) -o game $(OBJ)

clean:
	rm -f $(OBJ) game
