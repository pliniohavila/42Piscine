#include <unistd.h>
#include <fcntl.h>

#define MAX_BUF 1024

void    ft_cat(int fd);
void    clear_buf(char *);

int     main(int argc, char **argv)
{
    int     i;
    int     fd;

    if (argc == 1)
    {
        fd = STDIN_FILENO;
        ft_cat(fd);
    }
    else 
    {
        i = 1;
        while (i < argc)
        {
            fd = open(argv[i], O_RDONLY);
            if (fd == -1)
            {
                write(2, "Error opening the file\n", 30);
                return (1);
            }
            i++;
            ft_cat(fd);
        }
    }

    return (0);
}

void    clear_buf(char *buf)
{
    int     i;
    while(i < MAX_BUF)
        buf[i++] = '\0';
}

void    ft_cat(int fd)
{
    int     bytes_reads;
    int     bytes_writes;
    char    buf[MAX_BUF];

    bytes_reads = 0;
    bytes_writes = 0;
    clear_buf(buf);

    while ((bytes_reads = read(fd, buf, MAX_BUF - 1)) > 0)
    {
        buf[bytes_reads] = '\0';
        bytes_writes = write(1, buf, bytes_reads);
        if (bytes_writes != bytes_reads)
        {
            write(2, "Error reading the file\n", 30);
            if (fd != STDIN_FILENO)
                goto close_fd;
            return;
        }
    }

    if (bytes_reads == -1)
    {
        write(2, "Error reading the file\n", 30);
        goto close_fd;
        return;
    }

    write(1, "\n\n", 2);   
    goto close_fd;

close_fd:
    if (fd != STDIN_FILENO)
        close(fd); 
}
