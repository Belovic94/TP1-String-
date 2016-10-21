C = gcc
C_FLAGS = -g -O2 -std=c99 -Wall -Wconversion -Wno-sign-conversion
C_FLAGS += -Wbad-function-cast -Wshadow -Wpointer-arith -Wunreachable-code -Wformat=2 -Werror
DEFAULT = TP1
OBJ_STRUTIL = strutil.o
#OBJS =  strutil.o
VALGRIND = valgrind
V_FLAGS = --leak-check=full --track-origins=yes --show-reachable=yes

all: clean $(DEFAULT)

$(DEFAULT): $(OBJ_STRUTIL)
		$(CC) $(C_FLAGS) pruebas.c $(OBJ_STRUTIL) -o $(DEFAULT)

$(OBJ_STRUTIL): strutil.c strutil.h
		$(CC) $(C_FLAGS) strutil.c -c

run: $(DEFAULT)
		$(VALGRIND) $(V_FLAGS) ./$(DEFAULT)

clean_obj:
		rm -f *.o

clean: clean_obj
		rm -f $(DEFAULT)
