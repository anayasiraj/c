file = first

all: compile

compile: $(file).c
	gcc -Wall -Werror -fsanitize=address,undefined -g $(file).c -o $(file).out

clean:
	rm -rf $(file).out *-

