#include "others.h"

/*
 * The MAIN shell function with:
 * 1. UI() for prompt
 * 2. initialise() for getting user and host names
 * 3. main() which binds the entire shell together decides on the argument input by user
 * and runs/performs the required command
 */

char systemname[host_max], username[user_max], home[path_max], path[path_max];

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

int initialise()
{
    gethostname(systemname, host_max);

    /*struct utsname uts;
    int sysname = uname(&uts);
    if (sysname != 0)
    {
        perror("Error:");
        exit(1);
    }
    strcpy(systemname, uts.sysname);*/

    getlogin_r(username, user_max);
    getcwd(home, path_max);
    return 0;
}

int UI()
{
    int flag = 1;
    getcwd(path, path_max);

    for (int i = 0; i < strlen(home); i++)
        if (home[i] != path[i]) flag = 0;


    char foo[path_max];
    if (flag)
    {
        int i, index = 0;

        foo[index++] = '~';
        for (i = strlen(home); i < strlen(path); i++)
            foo[index++] = path[i];
        foo[index++] = '\0';

        strcpy(path, foo);
    }

    printf("\n<%s@%s:%s>", username, systemname, path);
    fflush(stdout);
    return 0;
}

void execute(char *line)
{
    size_t buff_size = 1000;
    char *echo_line = (char *) malloc(buff_size * sizeof(char));
    strcpy(echo_line, line);

    char *args[100] = {NULL};
    char d[10] = " \t\n";
    parse(line, args, d);

    if (strcmp(args[0], "exit") == 0)
        exit(0);
    else if (strcmp(args[0], "cd") == 0)
        CD(args);
    else if (strcmp(args[0], "pwd") == 0)
        PWD();
    else if (strcmp(args[0], "echo") == 0)
        ECHO(echo_line, d);
    else if (strcmp(args[0], "pinfo") == 0)
        PINFO(args);
    else if (strcmp(args[0], "ls") == 0)
        LSMAIN(args);
    else PRO(args);
}

int main(int argc, char *argv[])
{
    printf("HELLO, THERE! Welocome to Mariam :P");
    fflush(stdout);

    signal(SIGINT, FUNC_H);
    signal(SIGTERM, FUNC_H);
    signal(SIGCHLD, FUNC_H);

    initialise();

    while (1)
    {
        UI();

        size_t buff_size = 1000;
        char *line = (char *) malloc(buff_size * sizeof(char));
        read(0, line, buff_size * sizeof(char));

        char *block[20] = {NULL};

        parse(line, block, ";");

        for(int i = 0; block[i] != NULL; i++)
        {
            execute(block[i]);
        }
    }
}
