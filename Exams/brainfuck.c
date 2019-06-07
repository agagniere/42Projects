#include <unistd.h>
#include <stdint.h>

#define RIGHT 1
#define LEFT -1

char* matching_bracket(char* string, int way)
{
    int state;

    state = 0;
    do {
        if (*string == '[')
            state++;
        else if (*string == ']')
            state--;
        string += way;
    } while (state != 0);
    return (string - way);
}

void  interpret_brainfuck(char* source_code, uint8_t* buffer)
{
    char instruction;

    while ((instruction = *source_code) != '\0')
    {
        switch (instruction)
        {
        case '+': (*buffer)++;         break;
        case '-': (*buffer)--;         break;
        case '>': buffer++;            break;
        case '<': buffer--;            break;
        case '.': write(1, buffer, 1); break;
        case '[':
            if (*buffer == 0)
                source_code = matching_bracket(source_code, RIGHT);
            break;
        case ']':
            if (*buffer != 0)
                source_code = matching_bracket(source_code, LEFT);
            break;
        }
        source_code++;
    }
}

int   main(int ac, char** av)
{
    uint8_t buffer[2048];

    if (ac > 1)
    {
        unsigned i = sizeof buffer / sizeof *buffer;
        while (i --> 0)
            buffer[i] = 0;
        interpret_brainfuck(av[1], buffer);
    }
    else
        write(1, "\n", 1);
    return (0);
}
