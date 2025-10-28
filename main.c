#include "pipex.h"

static void second_child(int *fd,char **av, char **env)
{
    char    *path;
    char    **command;
    int     write;

    write = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
    if (write == -1)
        error_message(2);
    close(fd[1]);
    dup2(fd[0], STDIN_FILENO);
    dup2(write, STDOUT_FILENO);
    close(fd[0]);
    command = ft_split(av[3], ' ');
    if (!command || !*command)
        return (free_s(command));
    path = check_path(*command);
    if (!path || !*path)
    {
        free_s(command);
        error_message(3);
    }
    execve(path, command, env);
    free(path);
    free_s(command);
    error_message(4);
}

static void first_child(int *fd, int read, char **av, char **env)
{
    char    *path;
    char    **command;

    close(fd[0]);
    dup2(read, STDIN_FILENO);
    dup2(fd[1], STDOUT_FILENO);
    close(fd[1]);
    command = ft_split(av[2], ' ');
    if (!command || !*command)
        return (free_s(command));
    path = check_path(*command);
    if (!path || !*path)
    {
        free_s(command);
        error_message(3);
    }
    execve(path, command, env);
    free(path);
    free_s(command);
    error_message(4);
}

static void for_pipes_exit(void)
{
    int forexit;
    int status;

    forexit = 0;
    while (wait(&status) > 0)
    {
        if (WIFEXITED(status))
            forexit = WEXITSTATUS(status);
    }
    exit(forexit);   
}

static void for_pipe(int *fd, int read, char **av, char **env)
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
        if ((sec_pid = fork()) == -1)
            return ;
        else if (sec_pid == 0)
            second_child(fd, av, env);
    }
    close(fd[0]);
    close(fd[1]);
    for_pipes_exit();
}

int main(int ac, char **av, char **env)
{
    int fd[2];
    int read;

    if (ac != 5)
        error_message(0);
    if (pipe(fd) == -1)
        return (1);
    read = open(av[1], O_RDONLY);
    if (read == -1)
    {
        error_message(1);
        read = open("/dev/null", O_RDONLY);
    }
    if (access(av[4], F_OK) == 0)
    {
        if (access(av[4], W_OK) != 0)
            error_message(2);
    }
    for_pipe(fd, read, av, env);
    return (0);
}
