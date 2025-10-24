#include "pipex.h"

// useable functs  open, close, read, write,
// malloc, free, perror,
// strerror, access, dup, dup2,
// execve, exit, fork, pipe,
// unlink, wait, waitpid

int  main(int ac, char **av, char **env)
{
    int fd[2];
    char *path;

    if (ac != 5)
        error_message(0);
    fd[0] = open(av[1], O_RDONLY);
    if (fd[0] == -1)
        error_message(1);
    fd[1] = open(av[3], O_WRONLY | O_CREAT | O_TRUNC, 0777);
    if (fd[1] == -1)
        error_message(2);
    path = check_path(av[2]);
    if (!path)
        error_message(3);
    return (0);
}