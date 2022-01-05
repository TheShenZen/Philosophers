/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_sim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seciurte <seciurte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 17:44:23 by seciurte          #+#    #+#             */
/*   Updated: 2022/01/05 18:37:00 by seciurte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	spwan_philos(t_sim_rules *sim_rules, t_philo **philos)
{
	int			i;

	(*philos) = malloc(sizeof(t_philo) * sim_rules->nb_of_philos);
	if ((*philos) == NULL)
		return (-1);
	i = 0;
	while (i < sim_rules->nb_of_philos)
	{
		(*philos)[i].name = i;
		(*philos)[i].status = i % 3;
		(*philos)[i].nb_of_cycles = sim_rules->nb_of_cycles;
		if (pthread_create(&((*philos)[i].philo), NULL,
			start_work, &(*philos)[i]))
		{
			free((*philos));
			return (-1);
		}
		if (pthread_mutex_init(&((*philos)[i].mtx), NULL))
		{
			free((*philos));
			return (-1);
		}
		i++;
	}
	return (0);
}

void	give_philos_the_rules(t_philo **philos, t_sim_rules *sim_rules)
{
	int		i;

	i = 0;
	while (i < sim_rules->nb_of_philos)
	{
		(*philos)[i].time_to_die = sim_rules->time_to_die;
		(*philos)[i].time_to_eat = sim_rules->time_to_eat;
		(*philos)[i].time_to_sleep = sim_rules->time_to_sleep;
		i++;
	}
}

int	wait_for_philos(t_philo **philos, t_sim_rules *sim_rules)
{
	int		i;

	i = 0;
	while (i < sim_rules->nb_of_philos)
	{
		if (pthread_join((*philos)[i].philo, NULL))
		{
			free(*philos);
			return (-1);
		}
		i++;
	}
	return (0);
}