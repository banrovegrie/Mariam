#include "others.h"

extern char systemname[host_max], username[user_max], home[path_max], path[path_max];

int CD(char **args)
{
    char foo[path_max];
    strcpy(foo, home);

    int l = strlen(home);
    //printf("%s\n", args[1]);
    if (args[1] == NULL || strcmp(args[1], "\0") == 0) chdir(home);
    else if (args[1][0] != '~')
    {
        if (chdir(args[1]) != 0) perror("error in cd");
    } else if (args[1][0] == '~')
    {
        int i = 0;
        for (i = 1; args[1][i] != '\0'; i++)
            foo[i + l - 1] = args[1][i];
        foo[i + l - 1] = '\0';

        if (chdir(foo) != 0) perror("error in cd");
    } else if (chdir(args[1]) != 0) perror("error in cd");

    fflush(stdout);
    return 0;
}

int PWD()
{
    char foo[path_max];
    if (getcwd(foo, path_max) == NULL) perror("error in pwd");
    printf("%s", foo);

    fflush(stdout);
    return 0;
}

int ECHO(char *line, char *d)
{
    char *foo = strtok(line, d);
    foo = strtok(NULL, d);

    while (foo != NULL)
        printf("%s ", foo), foo = strtok(NULL, d);

    fflush(stdout);
    return 0;
}