#include "unistd.h"

int     main(int argc, char *argv[])
{
    int     i;
    int     cursor;
    char    *name;

    if (argc < 0)
        return (-1);

    cursor = 0;
    name = argv[0];
    while (name[cursor] != '\0')
        cursor++;

    while (name[cursor] != 92)
        cursor--;

    i = cursor + 1;
    while (name[i] != '\0')
    {
        write(1, &name[i], 1);
        i++;
    }
    write(1, "\n", 1);

    return (0);
}