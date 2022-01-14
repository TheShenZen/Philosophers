/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seciurte <seciurte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 16:08:37 by seciurte          #+#    #+#             */
/*   Updated: 2022/01/13 15:55:22 by seciurte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	philo_eat(t_philo *philo)
{
	long		time;

	philo_take_fork(philo, philo->name);
	philo_take_fork(philo, (philo->name + 1) % philo->sim_rules->nb_of_philos);
	time = get_time();
	printf("%ld %d is eating\n", time, philo->name);
	if (philo->forks[philo->name] == 0)
		philo->forks[philo->name]++;
	if (philo->forks[(philo->name + 1) % philo->sim_rules->nb_of_philos] == 0)
		philo->forks[(philo->name + 1) % philo->sim_rules->nb_of_philos]++;
	return (time);
}