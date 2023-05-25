#include <stdio.h>
#include <stdlib.h>


int     ft_strlen(char *str)
{
    int     count;

    count = 0;
    while (str[count] != '\0')
        count++;

    return (count);
}

char    *ft_strncat(char *dest, char *src, int nb)
{   
    int     i;
    int     j;

    i = (ft_strlen(dest));
    j = 0;
    while ((dest[i] == '\0') && (j < nb))
    {
        dest[i] = src[j];
        i++;
        j++;
    }

    dest[i] = '\0';

    return (dest);
}

// lembrar para voltar a char *
char    *ft_strjoin(int size, char **strs, char *sep)
{
    char    *strjoin;
    int     i;
    int     len_strjoin;

    if (size == 0)
    {
        strjoin = (char*)malloc(1);
        return strjoin;
    }

    i = 0;
    len_strjoin = 0;
    // Calc length of the new string
    while (i < size)
    {
        len_strjoin += ft_strlen(strs[i]);
        i++;    
    }
    // Add length relative to `sep` and spaces
    len_strjoin += ft_strlen(sep) * (size - 1);

    i = 0;
    // Alloc memory for new string joined
    strjoin = (char *)malloc(sizeof(char) * (len_strjoin + 1));
    if (strjoin == NULL)
        return NULL;
    // Set all box of the strjoin as 0
    while (i < len_strjoin)
    {
        strjoin[i] = '\0';
        i++;
    }

    i = 0;
    while (i < size)
    {
        strjoin = ft_strncat(strjoin, strs[i], ft_strlen(strs[i]));
        if (i < size - 1)
            strjoin = ft_strncat(strjoin, sep, ft_strlen(sep));

        i++;
    }

    return (strjoin);
}

int main(void)
{
    char    *strs[] = {"Hello", "Succession", "title"};
    char    *sep = ", ";
    char    *strjoin;
    int     size;

    size = sizeof(strs) / sizeof(char *);
    strjoin = ft_strjoin(size, strs, sep);

    printf("%s\n", strjoin);

    free(strjoin);
    return (0);
}