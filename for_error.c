/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkarali <zkarali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 13:24:08 by zkarali           #+#    #+#             */
/*   Updated: 2025/10/30 15:12:25 by zkarali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	error_message(int i)
{
	if (i == 0)
	{
		write(2, "Error: incorrect number of arguments\n", 37);
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
