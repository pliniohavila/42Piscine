#include <stdio.h>

void    ft_sort_string_tab(char**);
void    print_tab(char**);
int     ft_strcmp(char*, char*);
int     str_vector_len(char**);

int     main(void)
{
    char    *tab[] = {"hello", "void", "ft", "main", "all", NULL};

    printf("Before sort: ");
    print_tab(tab);
    ft_sort_string_tab(tab);
    printf("After sort: ");
    print_tab(tab);
    return (0);
}

void    ft_sort_string_tab(char **tab)
{
    char    *tmp;
    int     len;
    int     i;
    int     k;
    

    len = str_vector_len(tab);
    tmp = NULL;
    i = 0;
    while (i < len)
    {
        k = 0;
        while (k < len - 1)
        {
            if (ft_strcmp(tab[k], tab[k + 1]) > 0)
            {
                tmp = tab[k];
                tab[k] = tab[k + 1];
                tab[k + 1] = tmp;
            }
            k++;
        }
        i++;
    }
}

void    print_tab(char **tab)
{
    fflush(stdin);
    while (*tab != NULL)
        printf("%s ", *tab++);
    printf("\n");
}

int     ft_strcmp(char *s1, char *s2)
{
    unsigned char   c1;
    unsigned char   c2;

    while ((*s1 != '\0') || (*s2 != '\0'))
    {
        c1 = *s1++;
        c2 = *s2++;
        if (c1 != c2)
            return (c1 - c2);
    }
    return (0);
}

int     str_vector_len(char **tab)
{
    int     i;
    
    i = 0;
    while (tab[i] != NULL)
        i++;
    return (i);
}
