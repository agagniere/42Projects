/*
** Array to int
*/

#include <ctype.h>

int  ft_atoi(const char* str)
{
    int n = 0;
    int sign = 1;

    while (isspace(*str))
        str++;
    if ((*str == '+' || *str == '-') && (*str++ == '-'))
        sign = -1;
    while (isdigit(*str))
        n = 10 * n + sign * (*str++ - '0');
    return (n);
}
