#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include "includes/libft.h"
#include <stdio.h>

#define HEX "0123456789abcdef"
#define DECIMAL "0123456789"
#define SIZE_BUF_BASE 7
#define DEFAULT_BYTES 16

void    hexdump(int);
void    err(int);
void    print_caracter(char);
void    ft_putnbr_base(int, char *);

int     main (int argc, char **argv)
{
    int     fd;

    if (argc == 1)
    {
        fd = STDIN_FILENO;
        hexdump(fd);
    } 
    else 
    {
        if ((fd = open(argv[1], O_RDONLY)) == -1)
        {
            err(errno);
            return (1);
        }
        hexdump(fd);
    }

    return (0);
}

void    hexdump(int fd)
{   
    char    *buf;
    int     bytes_reads;
    int     line;
    int     offset;

    buf = malloc(sizeof(char) * DEFAULT_BYTES);
    if (buf == NULL)
    {
        err(errno);
        return;
    }
    offset = 0;
    while ((bytes_reads = read(fd, buf, DEFAULT_BYTES)) > 0)
    {
        line = -1;
        ft_putnbr_base(offset, HEX);
        while (line < bytes_reads)
        {
            print_caracter(buf[line]);
            ft_putstr("  ");
            line++;
        }
        offset++;
        ft_putchar('\n');
    }
    if (bytes_reads == -1)
    {
        err(errno);
        return;
    }
}

void    err(int error)
{
    ft_putstr("Error: ");
    ft_putstr(strerror(error));
    ft_putstr("\n");
}

void    print_caracter(char c)
{
    if ((c > 31) && (c < 126))
    {
        ft_putchar(32);
        ft_putchar(c);
    }
    else 
    {
        if (c == '\a')
            ft_putstr("\\a");
        if (c == '\b')
            ft_putstr("\\b");
        if (c == '\f')
            ft_putstr("\\f");
        if (c == '\n')
            ft_putstr("\\n");
        if (c == '\r')
            ft_putstr("\\r");
        if (c == '\t')
            ft_putstr("\\t");
        if (c == '\v')
            ft_putstr("\\v");
    }
}

int     valid_base(char *str)
{
    int     i;
    int     j;

    if (ft_strlen(str) < 2)
        return (0);
    i = 0;
    while (str[i] != '\0')
    {
        if ((str[i] == '-') || (str[i] == '+'))
            return (0);
        j = i + 1;
        while (str[j] != '\0')
        {
            if (str[j] == str[i])
                return (0);
            j++;
        }
        i++;
    }

    return (1);
}

void    ft_putnbr_base(int nb, char *base)
{
    if (valid_base(base) == 1)
    {
        int     i;
        int     j;
        int     k;
        int     len_base;
        int     mod;
        int     digits[SIZE_BUF_BASE];
        int     abs;

        i = SIZE_BUF_BASE;
        len_base = ft_strlen(base);
        if (nb >= 0)
            abs = nb;
        else 
            abs = nb * (-1);
        while (abs != 0)
        {
            mod = abs % len_base;            
            digits[i--] = base[mod];
            abs = (abs - mod) / len_base;
        }

        if (nb < 0)
            digits[i--] = 45;
        
        j = 1;
        k = i + 1;
        if (len_base == 16)
            while (j++ < k)
                write(1, "0", 1);
        while (k <= SIZE_BUF_BASE)
            write(1, &digits[k++], 1);
    }
}

