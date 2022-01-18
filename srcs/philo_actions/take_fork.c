/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_fork.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seciurte <seciurte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 15:45:38 by seciurte          #+#    #+#             */
/*   Updated: 2022/01/18 18:12:40 by seciurte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	philo_take_fork(t_philo *philo, int fork)
{
	pthread_mutex_lock(&(philo->mtx[philo->name]));
	if (philo->forks[fork] > 0)
		philo->forks[fork]--;
	if (print_status(philo->name, THINK))
		return (-1);
	pthread_mutex_unlock(&(philo->mtx[philo->name]));
	return (0);
}