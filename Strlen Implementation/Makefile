CC = gcc
CFLAGS = -Wall -Werror -g -Og -fsanitize=address,undefined

# Targets
all: testclient customtestclient

customtestclient: customtestclient.o strlib.o
	$(CC) -o $@ $^ $(CFLAGS)
testclient: testclient.o strlib.o
	$(CC) -o $@ $^ $(CFLAGS)

testclient.o: testclient.c
	$(CC) -c $< -o $@ $(CFLAGS)

customtestclient.o: customtestclient.c
	$(CC) -c $< -o $@ $(CFLAGS)

strlib.o: strlib.c
	$(CC) -c $< -o $@ $(CFLAGS)

# Clean target
clean:
	rm -f customtestclient testclient *.o *.txt
