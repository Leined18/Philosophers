/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 20:07:06 by danpalac          #+#    #+#             */
/*   Updated: 2024/10/20 20:39:56 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	*ft_error(char *err, int exit_code, t_memory *mem)
{
	if (err && *err)
		printf("%s", err);
	cleanup_data(&mem->data, &mem->philos);
	if (exit_code)
		exit(EXIT_FAILURE);
	return (NULL);
}

void	ft_success(char *msg, t_memory *mem)
{
	if (msg && *msg)
		printf("%s", msg);
	cleanup_data(&mem->data, &mem->philos);
	exit(EXIT_SUCCESS);
}