// #include <stdio.h>

#define AR_LENGTH(arr) sizeof(arr) / sizeof(arr[0])
#define foreach(a, i) for(i = 0; i < (AR_LENGTH(a)); i++)


int main()
{
    int     tab[] = {55, 12, 2, 3, 8};
    int     length;
    int     i;
    
    length = AR_LENGTH(tab);
    foreach(tab, i);
        printf("%d ", tab[i]);
    
    return 0;
}