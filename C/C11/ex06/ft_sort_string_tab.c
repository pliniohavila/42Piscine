#include <stdio.h>

void    ft_sort_string_tab(char**);
void    print_tab(char**);
int     ft_strcmp(char*, char*);

int     main(void)
{
    char    *tab[] = {"hello", "void", "ft", "main", "alltest", NULL};

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
    int     i;
    int     k;

    tmp = NULL;
    i = 0;
    while (tab[i] != NULL)
    {
        k = i;
        while (tab[k] != NULL)
        {
            if (ft_strcmp(tab[k], tab[k+1]) == 1)
            {
                printf("TMP P: %p - ", tab[k]);
                tmp = tab[k];
                printf("TMP: %s\n", tmp);
                // tab[k] = tab[k+1];
                // tab[k+1] = tmp;
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

    while (*s1 != '\0')
    {
        c1 = *s1++;
        c2 = *s2++;
        if (c1 != c2)
            return (c1 < c2 ? -1 : 1);
    }
    return (0);
}