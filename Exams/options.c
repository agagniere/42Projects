#include <unistd.h>
#include <stdint.h>

typedef uint32_t bitset;

#define ONE ((bitset)1)
#define MASK(V) (ONE << (V))
#define SET(S,V) (S |= MASK(V))
#define GET(S,V) (S & MASK(V))
#define INVALID 31

bitset parse_args(int count, char** values)
{
    bitset set;

    set = 0;
    while (count --> 0)
    {
        if (**values == '-')
            while (*++*values)
            {
                if ('a' <= **values && **values <= 'z')
                    SET(set, **values - 'a');
                else
                    SET(set, INVALID);
            }
        values++;
    }
    return (set);
}

void   BITSET_print(bitset set)
{
    unsigned i = 32;

    if (i == 0 || GET(set, 'h' - 'a'))
        write(1, "options: abcdefghijklmnopqrstuvwxyz", 35);
    else if (GET(set, INVALID))
        write(1, "Invalid Option", 14);
    else
        while (i --> 0)
        {
            write(1, GET(set,i) ? "1" : "0", 1);
            if (i && i % 8 == 0)
                write(1, " ", 1);
        }
    write(1, "\n", 1);
}

int    main(int ac, char** av)
{
    BITSET_print(parse_args(ac, av));
    return (0);
}
