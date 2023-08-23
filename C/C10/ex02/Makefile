
# local variables
CC		= gcc
FLAGS 	= -Wall -Wextra -Werror

# folders 
INCLUDE = ./includes
LIB     = ./libs

# rules
all:
	$(CC) $(FLAGS) ft_tail.c -L $(LIB)/ -l ft -o ft_tail

clean:
	rm -f *.o

fclean: clean
	rm -f ft_tail

run:
	./ft_tail -c 20 text.txt
