#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 01
// 0123456789
// 0123456789ABCDEF
// ./a.out 42 0123456789 01
// 42 0123456789 0123456789ABCDEF
// 2F 0123456789ABCDEF 01234567890
// "101010" 01 0123456789
// gcc -Wall -Wextra -Werror -g ft_convert_base.c
int ft_strlen(char *str)
{
    int     i;

    i = 0;
    while (str[i] != '\0')
        i++;

    return (i);
}   

int     valid_base(char *base)
{
    int     i;
    int     j;

    if (ft_strlen(base) < 2)
        return (0);

    i = 0;
    while (base[i] != '\0')
    {
        if (!(base[i] >= 48 && base[i] <= 57) && 
                !(base[i] >= 65 && base[i] <= 90) && 
                !(base[i] >= 97 && base[i] <= 122))
            {
                return (0); 
            }
        j = i + 1;
        while (base[j] != '\0')
        {
            if (base[j] == base[i])
                return (0);
            
            j++;
        }
        i++;
    }

    return (1);
}

int    is_include(char *base, char ch)
{
    while (*base)
    {
        if (*base == ch)
            return (1);

        base++;
    }

    return (0);
} 

int		value_of(char c)
{
	if (c >= '0' && c <= '9')
		return (c - '0');
	else if (c >= 'a' && c <= 'f')
		return (c - 'a' + 10);
	else if (c >= 'A' && c <= 'F')
		return (c - 'A' + 10);
	return (0);
}

int     ft_recursive_power(int nb, int power)
{
    if (power < 0)
        return (0);
    if (power == 0)
        return (1);

    return nb * ft_recursive_power(nb, (power - 1));
}

int     to_decimal(char *base, char *nbr, int start, int end)
{
    int     len_base;
    int     quantity_digits;
    int     result;

    len_base = ft_strlen(base);
    quantity_digits = end - start; // to calc power from digit position
    result = 0;
    // printf("LEN_BASE: %d\n", len_base);
    // printf("QTD_DIGITS: %d\n", quantity_digits);

    quantity_digits--;
    while (quantity_digits >= 0)
    {
        result = result + (value_of(nbr[start]) * (ft_recursive_power(len_base, quantity_digits)));
        start++;
        quantity_digits--;
    }
    // printf("\n");
    return (result);
}

void str_reverse(char *str)
{
    int len = strlen(str);
    int i;
    for (i = 0; i < len/2; i++)
    {
        char temp = str[i];
        str[i] = str[len-i-1];
        str[len-i-1] = temp;
    }
}

char *to_base(int nb, char *base, int len, char *resulted, int i)
{
    if (nb / len != 0)
        to_base(nb/len, base, len, resulted, ++i);
    
    if (nb/len == 0)
        i++;
        
    if (i >= 0)
        resulted[--i] = base[nb%len];

    return (resulted);
}

char    *ft_convert_base(char *nbr, char *base_from, char *base_to)
{
    int     cursor;
    int     sing;
    int     start;
    int     in_decimal;
    char    handle_convert[32];
    char    *converted;
    int     i;

    if (ft_strlen(nbr) < 1)
        return  NULL;

    if (valid_base(base_from) != 1 || valid_base(base_to) != 1)
        return NULL;

    cursor = 0;
    sing = 1;
    // move cursor to point where start digits 
    // and verify if the number is negative
    while (nbr[cursor] == 32 || nbr[cursor] == '-' || nbr[cursor] == '+')
    {
        if (nbr[cursor] == '-')
            sing = -sing;
        cursor++;
    }
    // move cursor for now there are valid digits in base_from 
    start = cursor;
    while (is_include(base_from, nbr[cursor]) == 1)
        cursor++;
    
    // "  +-+101010hjggjh"

    // Convert to decimal 
    in_decimal = to_decimal(base_from, nbr, start, cursor);
    // Convert to base_to
    for (int i = 0; i < 32; i++)
        handle_convert[i] = 0;

    converted = to_base(in_decimal, base_to, ft_strlen(base_to), handle_convert, 0);
    str_reverse(converted);
    i = ft_strlen(handle_convert) - 1;
    if (sing == (-1))
    {
        while(i >= 0 && i < 32)
        {
            handle_convert[i + 1] = handle_convert[i];
            i--;
        }
        handle_convert[0] = '-'; 
    }

    return (converted);    
}


int     main(int argc, char **argv)
{
    char    *nbr;
    char    *base_from;
    char    *base_to;

    if (argc < 3)
        return (-1);

    nbr = (char*)malloc(sizeof(char) * ft_strlen(argv[1]) + 1);
    base_from = (char*)malloc(sizeof(char) * ft_strlen(argv[2]) + 1);
    base_to = (char*)malloc(sizeof(char) * ft_strlen(argv[3]) + 1);

    nbr = strcpy(nbr, argv[1]);
    base_from = strcpy(base_from, argv[2]);
    base_to = strcpy(base_to, argv[3]);

    printf("NBR: %s\n", nbr);
    printf("BASE_FROM: %s\n", base_from);
    printf("BASE_TO: %s\n", base_to);
    printf("\n");


    printf("CONVERTED: %s\n", ft_convert_base(nbr, base_from, base_to));

    free(nbr);
    free(base_from);
    free(base_to);

    return (0);
}