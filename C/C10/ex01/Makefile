
# local variables
CC		= gcc
FLAGS 	= -Wall -Wextra -Werror

# folders 
INCLUDE = ./includes
LIB     = ./libs

# rules
all: 
	$(CC) $(FLAGS) ft_cat.c -o ft_cat

clean:
	rm -f *.o

fclean: clean
	rm -f ft_display_file

run:
	./ft_cat file1 file2 file3
