# Mariam

**About:** A Basic Shell implemented in C

## Features

1. `pwd`: Displays the name of the working directory.

2. `ls [-l -a] [directory]`: List all files and folders in a specified directory in alphabetical order

3. `cd [directory]`: Changes directory to the directory specified, throws an error if the directory does not exist.

4. `echo [arguments]`: Displays whatever is specified in `[arguments]`.

5. `exit`: Exits the shell

6. `pinfo [pid]`: Returns details of the task mentioned as PID. If PID is not mentioned then it operates on `a.out`/the specified shell program executable.


## Foreground and Background Processes
All other commands are treated as system commands like emacs, vim etc.
To run a process in the background, follow the command with a '&' symbol. Eg. emacs &.
Upon termination of a background process, the shell prints its PID and exit status.
Handles & no matter where it is in the end. eg. emacs& , emacs &, ls -l&.
Also returns number of background processes running currently.
Implemented in run.c
