#include "includes/libft.h"
#include <unistd.h>
#include <stdio.h>

void    ft_display_file(char *);

int     main(int argc, char **argv)
{
    int     i;

    if (argc < 2)
        ft_putstr("File name missing.\n");

    if (argc > 5)
        ft_putstr("Too many arguments.\n");

    i = 1;
    while (i < argc)
        ft_display_file(argv[i++]);

    return (0);
}

void    ft_display_file(char *file)
{
    // int     fd;
    // char    buf[1024];

    // fd = open(file, O_RDONLY)
    printf("FILE: %s\n", file);
}