# La siguiente no es necesariamente requerida, se agrega para
# mostrar como funciona.

.SUFFIXES: .o .cpp
.cpp.o:
	$(CC) -c $(CFLAGS) $<


# Macros

CC = g++
CFLAGS = -g -O2
SRC = black.cpp Card.cpp Card.h Player.cpp Player.h
OBJ = black.o Card.o Player.o


# Reglas explícitas

all: $(OBJ)
	$(CC) $(CFLAGS) -o black $(OBJ)

clean:
	$(RM) $(OBJ) black

# Reglas implícitas

Card.o: Card.cpp Card.h
Player.o: Player.cpp Player.h Card.h
black.o: black.cpp Card.h Player.h
