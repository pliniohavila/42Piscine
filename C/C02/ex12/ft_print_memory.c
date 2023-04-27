#include "unistd.h"
#include "stdio.h"

void    ft_puthex(char *);
void    put_address(void *);

void    *ft_print_memory(void *addr, unsigned int size)
{
    if (size == 0)
        return (addr);

    char    space;
    char    buff[16];
    char    *tmp;
    char    eol;

    space = 32;
    eol = '\n';
    for (unsigned int i = 0; i < size; i += 16)
    {
        put_address(addr + i);
        write(1, &space, 1);
        tmp = (char*)(addr + i);
        for (unsigned int j = 0; j < 16; j++)
        {
            buff[j] = tmp[j];
        }
        ft_puthex(buff);
        write(1, &space, 1);
        for (int k = 0; (k < 16) || (buff[k] != '\0'); k++)
        {
            write(1, &buff[k], 1);
        }
        write(1, &eol, 1);
    }
    write(1, &eol, 1);

    return (addr);
}

int main(void)
{
    char             *str;
    unsigned int     size;

    str = "prototipada da seguinte maneira que possa ser escrita em um arquivo ou na\0";
    size = (unsigned int)strlen(str);
    ft_print_memory(str, size);
    return (0);
}

void    put_address(void *address_pointer)
{
    uintptr_t   address_int;
    char        address_formated[16];
    char        t_p;

    address_int = (uintptr_t)address_pointer;
    t_p = ':';
    for (int i = 0; i < 16; i++) {
        address_formated[15 - i] = "0123456789abcdef"[address_int & 0xf];
        address_int >>= 4;
    }
    write(1, address_formated, 16);
    write(1, &t_p, 1);
}

void    ft_puthex(char *str)
{
    char    digits[] = "0123456789abcdef0123456789ABCDEF";
    char    hex_brute[2];
    char    ch;
    char    space;
    int     i;
    int     mod;
    int     space_control;

    space = 32;
    while(*str != '\0')
    {
        hex_brute[0] = '0';
        hex_brute[1] = '0';
        ch = *str;

        i = 1;
        while (ch != 0)
        {
            mod = (ch % 16);
            hex_brute[i] = digits[mod];
            ch = ((ch - mod) / 16);
            i--;
        }
        if (space_control == 2)
        {
            write(1, &space, 2);
            space_control = 0;
        }

        write(1, hex_brute, 2);
        space_control++;

        str++;
    }
}