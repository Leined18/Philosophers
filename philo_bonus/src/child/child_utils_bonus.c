/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 15:29:22 by danpalac          #+#    #+#             */
/*   Updated: 2024/11/04 13:34:30 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "child_bonus.h"

int	wait_processes(t_memory *mem)
{
	waitpid(-1, &mem->status, 0);
	return (1);
}