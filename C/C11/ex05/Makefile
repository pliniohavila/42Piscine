# local variables
CC		= gcc
FLAGS 	= -Wall -Wextra -Werror

# rules
all:
	$(CC) $(FLAGS) do-op.c -o do-op -g3

clean:
	rm -f do-op

run:
	./do-op 1 + 1

tests:
	./tests.sh