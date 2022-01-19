/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_fork.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seciurte <seciurte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 15:45:38 by seciurte          #+#    #+#             */
/*   Updated: 2022/01/19 18:50:28 by seciurte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	philo_take_fork(t_philo *philo, int fork)
{
	check_for_dead_philos(philo);
	pthread_mutex_lock(&(philo->mtx[fork]));
	if (philo->forks[fork] > 0)
	{
		philo->forks[fork]--;
		print_status(philo->name, FORK, philo);
		pthread_mutex_unlock(&(philo->mtx[fork]));
		return (1);
	}
	pthread_mutex_unlock(&(philo->mtx[fork]));
	return (0);
}
