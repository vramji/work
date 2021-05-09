
CC=g++
CFLAGS=-I.
DEPS = hiker.h
OBJ = hiker.o main.o 

hmake: $(OBJ)
	$(CC) -o hiker hiker.o main.o
.PHONY: clean

clean:
	rm -f *.o hiker  

