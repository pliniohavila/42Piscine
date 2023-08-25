
# local variables
CC		= gcc
FLAGS 	= -Wall -Wextra -Werror

# folders 
INCLUDE = ./includes
LIB     = ./libs

# rules
all:
	$(CC) $(FLAGS) ft_hexdump.c -L $(LIB)/ -l ft -o ft_hexdump

clean:
	rm -f *.o

fclean: clean
	rm -f ft_hexdump

run:
	./ft_hexdump text.txt
