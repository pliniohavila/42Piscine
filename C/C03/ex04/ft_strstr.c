#include "stdio.h"

char    *ft_strstr(char *str, char *to_find)
{
    int     flag;
    int     i;
    int     i_tmp;
    int     j;

    flag = 0;
    i = 0;
    while(str[i] != '\0')
    {
        j = 0;
        if (str[i] == to_find[j])
        {
            flag = 1;
            i_tmp = i;
            while ((to_find[j] != '\0') && (flag == 1))
            {
                if (str[i_tmp] != to_find[j])
                {
                    flag = 0;
                }
                j++;
                i_tmp++;
            }
            if (flag)
            {
                return (str + i);
            }
            flag = 0;
        }
        i++;
    }

    return NULL;
}

int     main(void)
{
    char str1[] = "O rato roeu a roupa do rei de Roma";
    char str2[] = "rei";
    char *result = ft_strstr(str1, str2);
    if (result == NULL) {
        printf("Substring não encontrada.\n");
    } else {
        printf("Substring encontrada em: %s\n", result);
    }

    return (0);
}