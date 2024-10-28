/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state_controller_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 10:01:08 by danpalac          #+#    #+#             */
/*   Updated: 2024/10/28 10:01:17 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils_bonus.h"

void	init_state_controller(t_data *data)
{
	data->state = malloc(sizeof(StateController));
	data->state->state = RUNNING;
	data->state->mutex = sem_open("state_mutex", O_CREAT, 0644, 1);
}

// Función para cambiar el estado de los filósofos centralmente
void	update_state(t_data *data, State new_state)
{
	sem_wait(data->state_controller->mutex);
	data->state_controller->state = new_state;
	sem_post(data->state_controller->mutex);
}

// Función para verificar el estado actual
State	get_state(t_data *data)
{
	sem_wait(data->state_controller->mutex);
	State current = data->state_controller->state;
	sem_post(data->state_controller->mutex);
	return (current);
}