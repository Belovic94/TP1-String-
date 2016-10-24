CFLAGS := -g -std=c99 -Wall -Wformat=2
CFLAGS += -Wshadow -Wpointer-arith -Wunreachable-code
CFLAGS += -Wconversion -Wno-sign-conversion -Wbad-function-cast
CFLAGS += -Werror
VALGRIND = valgrind
V_FLAGS = --leak-check=full --track-origins=yes --show-reachable=yes

all: paste more dc 
include deps.mk

clean_obj:
		rm -f *.o

clean: clean_obj
		rm -f paste more dc strutil
