#include "others.h"

/*
 *This file deals with functions related to running foreground
 * and background processes
 * 1. FGPRO() for foreground
 * 2. BGPRO() for background
 * 3. PRO() serves as the decider with checks the presence of "&"
 * and sends the process/command into foreground or background respectively
 */

int FGPRO(char **args)
{
    int status, pid;
    char *arr[100] = {NULL};

    arr[0] = malloc(100 * sizeof(char));
    strcpy(arr[0], args[0]);

    for (int i = 1; args[i] != NULL; i++)
    {
        arr[i] = malloc(100 * sizeof(char));
        strcpy(arr[i], args[i]);
    }

    if ((pid = fork()) < 0)
    {
        perror("error in fork");
        return 0;
    }

    if (pid)
        waitpid(pid, NULL, 0);
    else
    {
        //printf("%s\n", arr[0]);
        //fflush(stdout);
        if (execvp(arr[0], arr) == -1)
        {
            perror("error in command");
            return 0;
        }
    }

    fflush(stdout);
    return 0;
}

int BGPRO(char **args)
{
    int status, pid;
    char *arr[1000] = {NULL};

    arr[0] = malloc(100 * sizeof(char));
    strcpy(arr[0], args[0]);

    for (int i = 1; args[i] != NULL && strcmp(args[i], "&") == 0; i++)
    {
        arr[i] = malloc(100 * sizeof(char));
        strcpy(arr[i], args[i]);
    }


    if ((pid = fork()) < 0)
    {
        perror("error in fork");
        return 0;
    }

    if (pid)
        return 0;
    else
    {
        if (setpgid(0, 0) == -1)
        {
            perror("error in orphaning child");
            return 0;
        }

        if (execvp(arr[0], arr) == -1)
        {
            perror("error in command");
            return 0;
        }
    }

    fflush(stdout);
    return 0;
}

int PRO(char **args)
{
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
    else FGPRO(args);

    return 0;
}
