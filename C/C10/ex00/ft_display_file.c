#include <unistd.h>
#include <fcntl.h>
#include "includes/libft.h"

#define BUF_SIZE 1024

void    ft_display_file(char *);
void    clear_buf(char *);

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
    int     fd;
    int     bytes_reads;
    int     bytes_writes;
    char    buf[1024];

    fd = 0;
    fd = open(file, O_RDONLY);
    if (fd == -1)
    {
        write(2, "Error opening the file\n", 30);
        return;
    }

    bytes_reads = 0;
    bytes_writes = 0;
    clear_buf(buf);
    while((bytes_reads = read(fd, buf, BUF_SIZE)) > 0)
    {
        bytes_writes = write(1, buf, bytes_reads);
        if (bytes_writes != bytes_reads)
        {
            write(2, "Error reading the file\n", 30);
            close(fd);
            return;
        }
    }

    if (bytes_reads == -1)
    {
        write(2, "Error reading the file\n", 30);
        close(fd);
        return;
    }

    write(1, "\n\n", 2);    
    close(fd);    
}

void    clear_buf(char *buf)
{
    int     i;
    while(i < BUF_SIZE)
        buf[i++] = '\0';
}