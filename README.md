# Mariam

- Made by Alapan Chaudhuri. 
- Help/suggestions taken from codereview@SE and stackoverflow@SE.
- Completed the basic functionality in a duration of 2 days (i.e., work done till 10/09/20).
- Updates to follow.

## Prompt

A Basic Shell implemented in C. The `prompt` displays the USERNAME and HOSTNAME along with the relative path of the directory you are in, wrt the location of the executable.

## Features

1. `pwd`: Displays the name of the working directory.

2. `ls [-l -a] [directory]`: List all files and folders in a specified directory in alphabetical order.

3. `cd [directory]`: Changes directory to the directory specified, throws an error if the directory does not exist.

4. `echo [arguments]`: Displays whatever is specified in `[arguments]`.
    A very basic implementation of ECHO has been performed ignoring the vitalities and possibilities of the actual ECHO command. Environment variables, for example, can't be echoed, i.e., `echo $USER` doesn't work.  

5. `exit`: Exits the shell.

6. `pinfo [pid]`: Returns details of the task mentioned as PID. If PID is not mentioned then it operates on `a.out`/the specified shell program executable.
    This has been implemented by scrapping `/proc/[PID]/exec` and `/proc/[PID]/status`. Absolute Executable Path has also been printed for the user's benefit.

N.B.: Unnecessary spaces, tabs etc. have been accounted for in LS, CD, PWD and ECHO. Regarding LS, position of `[directory]` and `[flags]` are invariant wrt the result. 

## Foreground and Background Processes
1. All other commands are treated as system commands like emacs, vim, clear etc.
2. To run a process in the background, follow the command with a '&' symbol. Eg. emacs &. Implemented by orphaning the child process.

## Signal Handling
1. When the background process terminates it's PID and EXIT STATUS are shown.
2. INTERRUPT and TERMINATE signals have also been well inplemented.

N.B.: Why name of the process is not returned upon termination of the background process?
Reason: It is highly unsafe to use malloc() inside the respective `signal_handler()` functions. `fprintf` is relatively stable and thus has been used only to directly print the PID associated. Printing the name of the process has been ignored.

## Issues
1. A better global parser is to made.
2. Stress testing is to performed.
3. Possible errors related to `ls -l [-a]` implementation are to be looked into.
