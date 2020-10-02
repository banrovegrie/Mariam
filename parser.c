#include "others.h"

void parse(char *line, char **args, char *d)
{
    int index = 0;
    char *END;
    char *foo = strtok_r(line, d, &END);

    while (foo != NULL)
    {
        args[index] = foo, foo = strtok_r(NULL, d, &END);
        index += 1;
    }
    fflush(stdout);
}
