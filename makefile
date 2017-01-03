
# Macros

CC = g++
CFLAGS = -g -O2
SRC = black.cpp Card.cpp Card.h Player.cpp Player.h
OBJ = black.o Card.o Player.o


# Explicit rules

all: $(OBJ)
	$(CC) $(CFLAGS) -o black $(OBJ)

clean:
	$(RM) $(OBJ) black

# Implicit rules

Card.o: Card.cpp Card.h
Player.o: Player.cpp Player.h Card.h
black.o: black.cpp Card.h Player.h
