file = third

all: compile

compile: $(file).c
	gcc -Wall -Werror -fsanitize=address,undefined -g $(file).c -o $(file).out -lm

clean:
	rm -rf $(file).out *-
