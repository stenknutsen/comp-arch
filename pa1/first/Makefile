COMPILER = gcc
CCFLAGS = -Wall -ansi
all: first

first: first.o
	$(COMPILER) $(CCFLAGS) -o first first.o
first.o: first.c first.h
	$(COMPILER) $(CCFLAGS) -c first.c
clean:
	rm -f first first.o
