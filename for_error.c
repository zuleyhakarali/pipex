#include "pipex.h"

void    error_message(int i)
{
    if (i == 0)
    {
        perror("incorrect number of arguments");
        exit(1);
    }
    else if (i == 1)
        perror("input file");
    else if (i == 2)
    {
        perror("output file");
        exit(1);
    }
    else if (i == 3)
    {
        perror("command not found");
        exit(127);
    }
    else if (i == 4)
    {
        perror("execve failed");
        exit(1);
    }
}