COMPILER = gcc
CCFLAGS = -Wall -ansi -std=gnu99
all: second

second: second.o
	$(COMPILER) $(CCFLAGS) -o second second.o
second.o: second.c second.h
	$(COMPILER) $(CCFLAGS) -c second.c
clean:
	rm -f second second.o

