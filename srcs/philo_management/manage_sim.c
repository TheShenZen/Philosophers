/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_sim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seciurte <seciurte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 18:35:51 by seciurte          #+#    #+#             */
/*   Updated: 2022/01/17 15:02:43 by seciurte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*start_work(void *arg)
{
	t_philo				*philo;
	int					last_activity;
	int					last_meal;
	int					status;

	philo = (t_philo *)arg;
	last_activity = get_time();
	last_meal = get_time();
	status = philo->name % 2;
	while (philo->nb_of_cycles)
	{
		if (status == 0)
			philo_eat(philo);
		else
			philo_sleep(philo);
		status = (status + 1) % 3;
		if (philo->nb_of_cycles > 0)
			philo->nb_of_cycles--;
	}
	return (NULL);
}
