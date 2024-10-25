/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 18:39:51 by danpalac          #+#    #+#             */
/*   Updated: 2024/10/25 12:48:23 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define BONUS
#include "bonus.h"

static int	success(char *msg, t_memory *mem)
{
	if (msg && *msg)
	{
		printf("%s", GREEN);
		printf("%s", msg);
		printf("%s", RESET);
	}
	if (mem)
		clean_up(mem);
	return (1);
}
static int	error(char *msg, t_memory *mem)
{
	if (msg && *msg)
	{
		printf("%s", RED);
		printf("%s", msg);
		printf("%s", RESET);
	}
	if (mem)
		clean_up(mem);
	return (0);
}

int	main(int argc, char **argv)
{
	t_memory	memory;

	memory = (t_memory){0};
    if (!valid_args(argc, argv))
        return (error(ARGUMENTS_ERROR, &memory));
    memory.ac = argc;
    memory.av = argv;
	if (!init_mem(&memory))
		return (error(MEMORY_ERROR, &memory));
	printf("Hello World!\n");
	return (success(SUCCESS, &memory));
}
