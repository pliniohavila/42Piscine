
# local variables
CC		= gcc
FLAGS 	= -Wall -Wextra -Werror

# folders 
INCLUDE = ./includes
SRC 	= ./src
LIB     = ./libs

# rules
all: 
	$(CC) $(FLAGS) ft_display_file.c -L $(LIB)/ -l ft -I ./include -o ft_display_file

clean:
	rm -f *.o

fclean: clean
	rm -f ft_display_file

run:
	./ft_display_file file1 file2 file3
