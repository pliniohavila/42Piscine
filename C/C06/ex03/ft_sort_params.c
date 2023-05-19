#include "unistd.h"

void     ft_putstr(char *str)
{
    int     i;

    i = 0;
    while(str[i] != '\0')
    {
        write(1, &str[i], 1);
        i++;
    }
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
    return dest_start;
}


void    short_strings(char strs[][10], int size)
{
    int     i;
    int     j;
    char    str_tmp[10];

    i = 0;
    // bubble_sort 
    while (i < size)
    {
        j = 0;
        while (j < (size - 1))
        {
            if (strs[j + 1][0] < strs[j][0])
            {
                ft_strcpy(str_tmp, strs[j]);
                ft_strcpy(strs[j], strs[j + 1]);
                ft_strcpy(strs[j + 1], str_tmp);
            }
            j++;
        }
        i++;
    }
}

int     main(int argc, char **argv)
{
    int     i;
    int     j;
    if (argc < 1)
        return (-1);
    
    char    argvs[argc][10];

    i = 1;
    while (i < argc)
    {
        ft_strcpy(argvs[i - 1], argv[i]);
        i++;
    }

    i--;
    short_strings(argvs, i);
    j = 0;
    while (j < i)
    {
        ft_putstr(argvs[j]);
        write(1, "\n", 1);
        j++;
    }

    return (0);
}