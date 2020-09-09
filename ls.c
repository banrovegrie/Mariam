#include "others.h"

extern char systemname[host_max], username[user_max], home[path_max], path[path_max];

int LS(char *directory, int A)
{
    struct dirent **LIST;

    int NUM = scandir(directory, &LIST, 0, alphasort);
    if (NUM < 0)
    {
        perror("error in ls");
        return 0;
    }

    for (int i = 0; i < NUM; i++)
    {
        if (LIST[i]->d_name[0] == '.' && A == 0)
            continue;
        else printf("%s\n", LIST[i]->d_name);
    }

    return 0;
}

int LSL(char *directory, int A)
{
    struct dirent **LIST;
    struct stat ST;

    int NUM = scandir(directory, &LIST, 0, alphasort);
    if (NUM < 0)
    {
        perror("error in ls");
        return 0;
    }

    for (int i = 0; i < NUM; i++)
    {
        if (LIST[i]->d_name[0] == '.' && A == 0)
        {
            continue;
        } else if (stat(LIST[i]->d_name, &ST) == 0)
        {
            printf("%c", (S_ISDIR(ST.st_mode)) ? 'd' : '-');
            printf("%c", (ST.st_mode & S_IRUSR) ? 'r' : '-');
            printf("%c", (ST.st_mode & S_IWUSR) ? 'w' : '-');
            printf("%c", (ST.st_mode & S_IXUSR) ? 'x' : '-');
            printf("%c", (ST.st_mode & S_IRGRP) ? 'r' : '-');
            printf("%c", (ST.st_mode & S_IWGRP) ? 'w' : '-');
            printf("%c", (ST.st_mode & S_IXGRP) ? 'x' : '-');
            printf("%c", (ST.st_mode & S_IROTH) ? 'r' : '-');
            printf("%c", (ST.st_mode & S_IWOTH) ? 'w' : '-');
            printf("%c ", (ST.st_mode & S_IXOTH) ? 'x' : '-');

            printf("%2ld ", (unsigned long) (ST.st_nlink));

            printf("%s ", (getpwuid(ST.st_uid))->pw_name);
            printf("%s ", (getgrgid(ST.st_gid))->gr_name);

            printf("%5lld ", (unsigned long long) ST.st_size);

            char timer[14];
            strftime(timer, 14, "%h %d %H:%M", localtime(&ST.st_mtime));
            printf("%s ", timer);

            printf("%s\n", LIST[i]->d_name);
        } else
        {
            perror("error in permissions/details");
            return 0;
        }
    }
    return 0;
}

int LSMAIN(char *line)
{
    int index = 0, A = 0, L = 0, count = 0;

    char *d = " \t\n";
    char *foo = strtok(line, d);
    char *str[100] = {NULL};

    while (foo != NULL)
    {
        printf("%s\n", foo);
        if (foo[0] == '-')
        {
            if (strcmp(foo, "-l") == 0) L = 1;
            else if (strcmp(foo, "-a") == 0) A = 1;
            else if (strcmp(foo, "-la") == 0) A = 1, L = 1;
            else if (strcmp(foo, "-al") == 0) A = 1, L = 1;
            count --;
        }

        str[index] = foo, foo = strtok(NULL, d);
        str[index][strlen(str[index])] = '\0';
        index += 1;
        count++;
    }

    printf("L:%d A:%d index:%d\n", L, A, index);

    if (count == 1)
    {
        if (L == 1) LSL(".", A);
        else LS(".", A);
        return 0;
    }

    /*for (int i = 1; i < index; i++)
    {
        char *rel_path = malloc(path_max * sizeof(char));
        if (getcwd(rel_path, path_max) == NULL) perror("error in cwd");

        char *resolved_path = malloc(path_max * sizeof(char));

        printf("%s\n", str[i]);

        if (str[i][0] == '~')
        {
            strcpy(rel_path, home);
            int l = strlen(home);

            int ind = 0;
            for (ind = 1; str[i][ind] != '\0'; ind++)
                rel_path[ind + l - 1] = str[i][ind];
            rel_path[ind + l - 1] = '\0';

        } else if (str[i][0] == '/')
        {
            strcpy(rel_path, str[i]);
            strcat(rel_path,"\0");
        }
        else if(str[i][0] == '\0' || str[i] == NULL)
        {
            //empty
        }
        else
        {
            strcat(rel_path, "/");
            strcat(rel_path, str[i]);
            strcat(rel_path, "\0");
        }

        printf("%s\n", rel_path);
        if (realpath(rel_path, resolved_path) == NULL)
        {
            perror("error in locating directory");
            return 0;
        }
        printf("%s\n", resolved_path);

        if (L == 1) LSL(resolved_path, A);
        else LS(resolved_path, A);

        free(rel_path);
        free(resolved_path);
        rel_path = NULL, resolved_path = NULL;
    }*/

    return 0;
}