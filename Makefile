CC=clang
CFLAGS=-g -Wall
OBJS=main.o

.phony all:
all: main

main: $(OBJS)
	$(CC) $(CLAGS) $(OBJS) -o $@ 

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ 

.phony run:
run:
	./main

.phony clean:
clean:
	@rm -rf main *.o ./main.dSYM

