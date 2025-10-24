#include "pipex.h"

void error_message(int i)
{
    if (i == 0)
    {
        perror("An incorrect number of arguments were entered\n");
        exit(1);
    }
    else if (i == 1)
    {
        perror("Input file is not valid\n");
        exit(1);
    }
    else if (i == 2)
    {
        perror("Cannot create the output file\n");
        exit(1);
    }
    else if (i == 3)
    {
        perror("Command not found\n");
        exit(127); //neden 127
    }
}