#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include "includes/libft.h"
#include <stdio.h>

static void    ft_tail(int, char*);

int     main(int argc , char **argv)
{
    if (argc < 2)
    {
        ft_putstr("Usage: ./ft_tail [OPTION (-c <50>)] [FILE]\n");
        return (1);
    }
  
    ft_tail(20, argv[1]);

    return (0);
}


static void    ft_tail(int bytes, char *file)
{
    int     fd;    

    fd = open(file, O_RDONLY);

    int     bytes_reads;
    // int     bytes_writes;
    char    *buf;

    bytes_reads = 0;
    buf = malloc(sizeof(char) * bytes * 2);
    // bytes_writes = 0;

    // int i = 0;
    while ((bytes_reads = read(fd, buf, (bytes * 2) - 1)) > 0)
    {
        buf[bytes_reads - 1] = '\0';
        printf("%d: %s\n", ft_strlen(buf), buf);
    }

    if (bytes_reads == -1)
    {
        ft_putstr("Error: ");
        ft_putstr(strerror(errno));
        ft_putstr("\n");
        free(buf);
        return;
    }
    printf("\n\n");
    int start = ft_strlen(buf) - bytes;
    printf("Len: %d \nStart: %d [[ %s ]]\n", ft_strlen(buf), start, buf);
    // ft_putstr(buf);
    // ft_putstr("\n----\n");
    // char *tail = buf + start;
    // ft_putstr(tail);
    // ft_putstr("\n");
    close(fd);
    free(buf);
}