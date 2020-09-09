#include "others.h"

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
            printf("%1s", (ST.st_mode & S_IRGRP) ? 'r' : '-');
            printf("%1s", (ST.st_mode & S_IWGRP) ? 'w' : '-');
            printf("%1s", (ST.st_mode & S_IXGRP) ? 'x' : '-');
            printf("%1s", (ST.st_mode & S_IROTH) ? 'r' : '-');
            printf("%1s", (ST.st_mode & S_IWOTH) ? 'w' : '-');
            printf("%1s ", (ST.st_mode & S_IXOTH) ? 'x' : '-');

            printf("%2ld ", (unsigned long) (ST.st_nlink));

            printf("%s ", (getpwuid(ST.st_uid))->pw_name);
            printf("%s ", (getgrgid(ST.st_gid))->gr_name);

            printf("%5lld ", (unsigned long long) ST.st_size);

            char timer[14];
            strftime(timer, 14, "%h %d %H:%M", localtime(&ST.st_mtime));
            printf("%s ", timer);

            printf("%s\n", LIST[i]->d_name);
        }
        else
        {
            perror("error in permissions/details");
            return 0;
        }
    }
    return 0;
}

int LSMAIN(char *line)
{
    
}