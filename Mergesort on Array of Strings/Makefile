CC = gcc
CFLAGS = -Wall -Werror -g -Og -fsanitize=address,undefined

# Targets
all: second

second: second.o ../first/strlib.o
	$(CC) -o $@ $^ $(CFLAGS)
leakdetect: second.c ../first/strlib.c
	$(CC) -o second second.c -Wall -Werror -g -Og
second.o: second.c
	$(CC) -c $< -o $@ $(CFLAGS)

../first/strlib.o: ../first/strlib.c
	$(CC) -c $< -o $@ $(CFLAGS)

# Clean target
clean:
	rm -f second ../first/strlib.o second.o