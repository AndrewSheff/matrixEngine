CC = clang
CFLAGS = -Wall -Wextra -std=c17 -g -Iinclude
SRC = src/main.c src/screen.c src/entity.c src/object.c src/scene.c src/message.c
OBJ = $(SRC:.c=.o)
TARGET = game

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)

.PHONY: all clean