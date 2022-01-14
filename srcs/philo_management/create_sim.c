/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_sim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seciurte <seciurte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 17:44:23 by seciurte          #+#    #+#             */
/*   Updated: 2022/01/10 16:54:54 by seciurte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	spwan_philos(t_sim_rules *sim_rules, t_philo *philos)
{
	int			i;

	i = 0;
	while (i < sim_rules->nb_of_philos)
	{
		if (pthread_create(&(philos[i].philo), NULL,
			start_work, &philos[i]))
		{
			free(philos);
			return (-1);
		}
		i++;
	}
	return (0);
}

int	wait_for_philos(t_philo *philos, t_sim_rules *sim_rules)
{
	int		i;

	i = 0;
	while (i < sim_rules->nb_of_philos)
	{
		if (pthread_join(philos[i].philo, NULL))
		{
			free(philos);
			return (-1);
		}
		i++;
	}
	return (0);
}