#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

int main(int ac, char **av);
char *check_path(char *command);
void error_message(int i);

# endif