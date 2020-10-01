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
    char *args[100] = {NULL};
    char d[10] = " \t\n";
    parse(line, args, d);

    int bg_flag = 0;
    for (int i = 1; args[i] != NULL; i++)
    {
        if (strcmp(args[i], "&") == 0)
        {
            bg_flag = 1;
            break;
        }
    }
    if (bg_flag) BGPRO(args);
    else check_redirection(args);
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
        int r_value = read(0, line, buff_size * sizeof(char));
        line = realloc(line, (sizeof(char) * (r_value + 1)));
        line[r_value] = '\0';

        char *block[20] = {NULL};

        parse(line, block, ";\n");

        for(int i = 0; block[i] != NULL; i++)
        {
            execute(block[i]);
        }
    }
}
