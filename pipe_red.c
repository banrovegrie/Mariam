#include "others.h"

extern char systemname[host_max], username[user_max], home[path_max], path[path_max];

void DO(char **args)
{

    if (strcmp(args[0], "pwd") == 0)
        PWD();
    else if (strcmp(args[0], "echo") == 0)
        ECHO(args);
    else if (strcmp(args[0], "pinfo") == 0)
        PINFO(args);
    else if (strcmp(args[0], "ls") == 0)
        LSMAIN(args);
    else
    {
        if (execvp(args[0], args) == -1)
        {
            perror("error in command");
            return;
        }
    }

    _exit(0);
}

void check_redirection(char **args)
{
	char *str[100] = {NULL};
	int f_in = 0, f_out = 1, f_stdin = dup(0), f_stdout = dup(1), index = 0;

	for (int i = 0; args[i] != NULL; i++)
	{
		if (args[i][0] == '<')
		{
			f_in = open(args[i + 1], O_RDONLY);
			if (f_in == -1)
			{
				perror("error in opening file");
				return;
			}
			i++;
		}
		else if (args[i][0] == '>')
		{
			if (sizeof(args[i]) > (int)(2 * sizeof(char)) && args[i][1] == '>')
			{
				f_out = open(args[i + 1], O_CREAT | O_WRONLY | O_APPEND, 0644);
				if (f_out == -1)
				{
					perror("error in creating/opening file");
					return;
				}
			}
			else
			{
				f_out = creat(args[i + 1], 0644); 
				if (f_out == -1)
				{
					perror("error in creating/opening file");
					return;
				}
			}
			i++;
		}
		else
		{
			str[index++] = strdup(args[i]); 
		}
	}

	dup2(f_in, 0), dup2(f_out, 1);

	int pid = fork();
	if (pid < 0)
    {
    	perror("error in pid");
    	return;
    }
	else if (pid == 0)
	{
	    DO(str);
	}
	else
	{
		signal(SIGINT, SIG_DFL);
    	signal(SIGTSTP, SIG_DFL);
		
		waitpid(pid, NULL, 0);
	    dup2(f_stdin, 0), dup2(f_stdout, 1);
	}

	fflush(stdout);
	return;
}

void PIPE(char *line, char **args)
{
	char *block[20] = {NULL};
	parse(line, block, "|");

	if (block[1] == NULL)
	{
		check_redirection(args);
	}	
	else
	{
		int old_fd_in = 0, f_stdin = dup(0), f_stdout = dup(1), i = 0;

		for (i = 0; block[i + 1] != NULL; i++)
		{
			int fd[2], id;
			if (pipe(fd) == -1)
			{
				perror("error in piping");
				return;
			}

			char *str[50] = {NULL};
			parse(block[i], str, " \t\n");

			if ((id = fork()) < 0)
			{
				perror("error in pid");
				return;
			}
			else if (id == 0)
			{
				/* Child Process */
				close(fd[0]);
				dup2(old_fd_in, 0), dup2(fd[1], 1);
				DO(str);	
			}
			else
			{
				signal(SIGINT, SIG_DFL);
	    		signal(SIGTSTP, SIG_DFL);
				
				/* Parent Process */
				close(fd[1]);
				waitpid(id, NULL, 0);
				old_fd_in = fd[0];
			}
		}

		char *str[50] = {NULL};
		parse(block[i], str, " \t\n");

		int id;
		if ((id = fork()) < 0)
		{
			perror("error in pid");
			return;
		}
		else if (id == 0)
		{
			/* Child Process */
			dup2(old_fd_in, 0), dup2(f_stdout, 1);
			DO(str);
		}
		else
		{
			signal(SIGINT, SIG_DFL);
	    	signal(SIGTSTP, SIG_DFL);

			/* Parent Process */
			waitpid(id, NULL, 0);
		    dup2(f_stdin, 0), dup2(f_stdout, 1);
		}
	}

	fflush(stdout);
	return;
}
