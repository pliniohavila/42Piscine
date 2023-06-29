
# local variables
CC		= gcc
FLAGS 	= -Wall -Wextra -Werror

# folders 
INCLUDE = ./includes
SRC 	= ./src

#objects
OBJS 	= ft_putchar.o ft_swap.o ft_putstr.o ft_putstr.o ft_strlen.o ft_strcmp.o

# rules
program:
	$(CC) $(FLAGS) main.c -L . -l ft -I ./include -o main

all: libft
	ar rc libft.a $(SRC)/*.o $(INCLUDE)/*.h

libft: $(OBJS)

%.o: $(SRC)/%.c
	$(CC) $(FLAGS) -c $< -o $(SRC)/$@

clean:
	rm -f $(SRC)/*.o

fclean: clean
	rm -f *.a

re: fclean all

