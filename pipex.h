/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkarali <zkarali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 13:25:02 by zkarali           #+#    #+#             */
/*   Updated: 2025/10/30 15:54:10 by zkarali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft/libft.h"
# include <unistd.h> //access, execve, pipe, dup2, fork, close, read, write
# include <stdio.h>  //perror
# include <errno.h>
# include <stdlib.h> //malloc, free, exit, NULL
# include <fcntl.h>  //open()
# include <sys/wait.h> //wait(), waitpid()

int		main(int ac, char **av, char **env);
char	*check_path(char *command);
void	free_s(char **s);
void	error_message(int i);

#endif