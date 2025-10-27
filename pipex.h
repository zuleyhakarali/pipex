#ifndef PIPEX_H
# define PIPEX_H

# include "libft/libft.h"
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/wait.h>

int main(int ac, char **av, char **env);
char *check_path(char *command);
void error_message(int i);

# endif