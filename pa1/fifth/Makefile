COMPILER = gcc
CCFLAGS = -Wall -ansi -std=gnu99
all: fifth

fifth: fifth.o
	$(COMPILER) $(CCFLAGS) -o fifth fifth.o
fifth.o: fifth.c fifth.h
	$(COMPILER) $(CCFLAGS) -c fifth.c
clean:
	rm -f fifth fifth.o

