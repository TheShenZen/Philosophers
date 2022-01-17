/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_fork.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seciurte <seciurte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 15:45:38 by seciurte          #+#    #+#             */
/*   Updated: 2022/01/17 11:51:38 by seciurte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	philo_take_fork(t_philo *philo, int fork)
{
	long		time;

	time = get_time();
	pthread_mutex_lock(&(philo->mtx[philo->name]));
	if (philo->forks[fork] > 0)
		philo->forks[fork]--;
	printf("%ld %d has taken a fork\n", time, philo->name);
	pthread_mutex_unlock(&(philo->mtx[philo->name]));
	return (1);
}