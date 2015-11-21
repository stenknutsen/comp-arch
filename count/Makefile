COMPILER = gcc
CCFLAGS = -lm
all: count

count: count.o
	$(COMPILER) $(CCFLAGS) -o count count.o
count.o: count.c count.h
	$(COMPILER) $(CCFLAGS) -c count.c
clean:
	rm -f count count.o
