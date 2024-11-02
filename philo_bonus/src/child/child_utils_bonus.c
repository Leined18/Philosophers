/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 15:29:22 by danpalac          #+#    #+#             */
/*   Updated: 2024/11/02 15:42:58 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "child_bonus.h"

int	wait_processes(t_memory *memory)
{
	(void)memory;
	waitpid(-1, NULL, 0);
	return (1);
}

pid_t	fork_process(void child_func(void *), void *info)
{
	pid_t pid;

	pid = fork();
	if (pid == 0)
		child_func(info);
	return (pid);
}
