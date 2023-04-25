#include "stdio.h"

char    char_uppercase(char ch)
{
    char    ch_upper;

    if (!((ch >= 'A') && (ch <= 'Z')))
    {
        ch_upper = ch - 32;
        return (ch_upper);
    }

    return (ch);
}

char    *ft_strcapitalize(char *str)
{
    int     i;

    i = 0;
    str[i] = char_uppercase(str[i]);
    i++;
    while(str[i] != '\0')
    {
        if (!((str[i] >= '0') && (str[i] <= '9')))
        {
            if (str[i - 1] == ' ')
            {
                str[i] = char_uppercase(str[i]);
            }
        }
        i++;
    }
    return (str);
}

int     main(void)
{
    char    str[] = "oi, tudo bem? 42palavras quarenta-e-duas; cinquenta+e+um";
    char    *capitalized;

    printf("Before: %s\n", str);
    capitalized = ft_strcapitalize(str);
    printf("After: %s\n", capitalized);

    return (0);
}
