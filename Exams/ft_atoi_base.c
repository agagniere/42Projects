/*
** Array to int with a base between 2 and 16
*/

#include <ctype.h>
#include <string.h>

int  ft_atoi_base(const char* str, int base)
{
    int         n = 0;
    int         sign = 1;
    const char* digits = "0123456789abcdef";

    if ((*str == '+' || *str == '-') && (*str++ == '-'))
        sign = -1;
    while (isalnum(*str))
    {
        char        c = *str++ | (1 << 5);
        const char* digit = memchr(digits, c, base);
        if (digit == NULL)
            break ;
        n = base * n + sign * (digit - digits);
    }
    return (n);
}
