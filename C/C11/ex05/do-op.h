#ifndef DO_OP_H
#define DO_OP_H

#include <unistd.h>

#define MAX_BUFFER 127

int     check_is_int(char);
int     ft_atoi(char*);
char    *ft_strcpy(char *, char *);
int     ft_strcmp(char *, char *);
void    ft_putstr(char *);
void    ft_putnbr(int);
int     sum(int, int);
int     sub(int, int);
int     mul(int, int);
int     div(int, int);
int     mod(int, int);

int (*operators[])(int, int) = { sum, sub, mul, div, mod } ;

#endif