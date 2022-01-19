/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_sim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seciurte <seciurte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 18:35:51 by seciurte          #+#    #+#             */
/*   Updated: 2022/01/19 15:54:36 by seciurte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*start_work(void *arg)
{
	t_philo				*philo;
	int					status;

	philo = (t_philo *)arg;
	status = philo->name % 2;
	while (philo->nb_of_cycles && !philo->sim_rules->stop)
	{
		if (status == 0 && !philo->sim_rules->stop)
		{
			philo->last_meal = philo_eat(philo);
			if (philo->last_meal == -1)
				return (NULL);
		}
		else if (!philo->sim_rules->stop)
			philo_sleep(philo);
		status = (status + 1) % 2;
		if (philo->nb_of_cycles > 0)
			philo->nb_of_cycles--;
	}
	return (NULL);
}
