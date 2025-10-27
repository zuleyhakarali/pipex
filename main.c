#include "pipex.h"

// useable functs  open, close, read, write,
// malloc, free, perror,
// strerror, access, dup, dup2,
// execve, exit, fork, pipe,
// unlink, wait, waitpid

void second_child(int *fd, int write, char **av, char **env)
{
    char *path;
    char **command;

    close(fd[1]);
    dup2(fd[0], STDIN_FILENO);
    dup2(write, STDOUT_FILENO);
    close(fd[0]);
    command = ft_split(av[3], ' ');
    path = check_path(*command);
    if (!path)
        error_message(3);
    execve(path, command, env);
}

void first_child(int *fd, int read, char **av, char **env)
{
    char *path;
    char **command;

    close(fd[0]);
    dup2(read, STDIN_FILENO);
    dup2(fd[1], STDOUT_FILENO);
    close(fd[1]);
    command = ft_split(av[2], ' ');
    path = check_path(*command);
    if (!path)
        error_message(3);
    execve(path, command, env);
}

void for_pipe(int *fd, int read, int write, char **av, char **env)
{
    int fir_pid;
    int sec_pid;

    fir_pid = fork();
    if (fir_pid == -1)
        return ;
    else if (fir_pid == 0)
        first_child(fd, read, av, env);
    else
    {
        sec_pid = fork();
        if (sec_pid == -1)
            return ;
        else if (sec_pid == 0)
            second_child(fd, write, av, env);
    }
    close(fd[0]);
    close(fd[1]);
    waitpid(fir_pid, NULL, 0);
    waitpid(sec_pid, NULL, 0);
}

int  main(int ac, char **av, char **env)
{
    int fd[2];
    int read;
    int write;

    if (ac != 5)
        error_message(0);
    if (pipe(fd) == -1)
        return (1);
    read = open(av[1], O_RDONLY);
    if (read == -1)
        error_message(1);
    write = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
    if (write == -1)
        error_message(2);
    for_pipe(fd, read, write, av, env);
    return (0);
}
