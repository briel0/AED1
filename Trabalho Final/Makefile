CC = gcc
CFLAGS = -Wall -Wextra -g

SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)
BIN = a.out

all: $(BIN)

$(BIN): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(BIN)

clean:
	rm -f *.o $(BIN)

run: all
	./$(BIN)