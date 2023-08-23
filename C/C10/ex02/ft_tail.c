#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include "includes/libft.h"

void    ft_tail(int, char*);
char    *ft_strcpy(char*, char*);
int     ft_atoi(char *str);
void    err(int);

int     main(int argc , char **argv)
{
    int     bytes;
    int     i;

    if (argc < 2)
    {
        ft_putstr("Usage: ./ft_tail [OPTION (-c <50>)] [FILE]\n");
        return (1);
    }

    bytes = 20;
    i = 1;
    while (i < (argc - 1))
    {
        if (ft_strcmp(argv[i], "-c") == 0)
        {
            bytes = ft_atoi(argv[i + 1]);
            if (bytes == 0)
                return (1);
        }
        i++;     
    }
  
    ft_tail(bytes, argv[argc - 1]);

    return (0);
}

void    ft_tail(int bytes, char *file)
{
    int     fd;  
    int     bytes_reads;
    int     start;
    char    *buf;
    char    *extra_buf;  

    fd = open(file, O_RDONLY);
    if (fd == -1)
    {
        err(errno);
        return;
    }

    bytes_reads = 0;
    buf = malloc(sizeof(char) * bytes);
    extra_buf = malloc(sizeof(char) * bytes);
    if ((buf == NULL) || (extra_buf == NULL))
    {
        err(errno);
        return;
    }

    while ((bytes_reads = read(fd, buf, bytes - 1)) > 0)
    {
        if (bytes_reads == (bytes - 1))
            ft_strcpy(extra_buf, buf);
        buf[bytes_reads] = '\0';
    }

    if (bytes_reads == -1)
    {
        err(errno);
        free(buf);
        free(extra_buf);
        return;
    }

    start = (ft_strlen(buf) - bytes) * (-1);
    if (start == 0)
        ft_putstr(buf);
    else 
    {
        ft_putstr(extra_buf + (ft_strlen(extra_buf) + (-start)));
        ft_putstr(buf);
    }

    close(fd);
    free(buf);
    free(extra_buf);
}

void     err(int erro)
{
    ft_putstr("Error: ");
    ft_putstr(strerror(erro));
    ft_putstr("\n");
}


char    *ft_strcpy(char *dest, char *src)
{
    if (dest ==  NULL)
        return NULL;
    char    *dest_start;    

    dest_start = dest;
    while(*src != '\0')
    {
        *dest = *src;
        src++;
        dest++;
    }

    *dest = '\0';
    return (dest_start);
}

int     check_is_int(char ch)
{
    if ((ch == 32) || (ch == '-') || (ch == '+'))
        return (1);
    else if (ch >= '0' && ch <= '9')
        return (1);

    return (0);
}

int     ft_atoi(char *str)
{
    int     result;
    int     count_subtractions;
    int     i;

    result = 0;
    count_subtractions = 0;
    i = 0;
    while (check_is_int(str[i]) != 0)
    {
        if (str[i] == '-')
            count_subtractions++;
        if ((str[i] >= '0') && (str[i] <= '9'))
            result = result * 10 + (str[i] - '0');
        i++;
    }
 
    if ((count_subtractions % 2) != 0)
        result *= (-1);

    return result;
}

// diff <(tail -c 20 text.txt) <(./ft_tail text.txt)
// diff <tail -c 20 text.txt <./ft_tail text.txt