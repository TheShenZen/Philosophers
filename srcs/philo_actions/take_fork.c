/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_fork.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seciurte <seciurte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 15:45:38 by seciurte          #+#    #+#             */
/*   Updated: 2022/01/19 16:06:19 by seciurte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	check_for_dead_philos(t_philo *philo)
{
	if (is_dead(philo->sim_rules->time_to_die, philo->last_meal) &&
		philo->sim_rules->stop == 0)
	{
		printf("%ld %d died\n", get_time(), philo->name);
		philo->sim_rules->stop = 1;
	}
}

int	philo_take_fork(t_philo *philo, int fork)
{
	pthread_mutex_lock(&(philo->mtx[fork]));
	check_for_dead_philos(philo);
	if (philo->forks[fork] > 0)
	{
		philo->forks[fork]--;
		if (print_status(philo->name, FORK, philo))
		{
			pthread_mutex_unlock(&(philo->mtx[fork]));
			return (0);
		}
		pthread_mutex_unlock(&(philo->mtx[fork]));
		return (1);
	}
	pthread_mutex_unlock(&(philo->mtx[fork]));
	return (0);
}