/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seciurte <seciurte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 16:08:37 by seciurte          #+#    #+#             */
/*   Updated: 2022/01/19 16:01:01 by seciurte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	take_forks(t_philo *philo)
{
	int						forks;

	forks = 1;
	while (philo_take_fork(philo, philo->name) == 0)
		if (philo->sim_rules->stop)
			return (-1);
	while (philo_take_fork(philo,
		(philo->name + 1) % philo->sim_rules->nb_of_philos) == 0)
		if (philo->sim_rules->stop)
			return (-1);
	return (0);
}

int	philo_eat(t_philo *philo)
{
	int			time;
	int			flag;

	flag = 0;
	if (print_status(philo->name, THINK, philo))
		return (-1);
	if (take_forks(philo))
		return (-1);
	if (print_status(philo->name, EAT, philo))
		return (-1);
	time = get_time();
	usleep(1000 * philo->sim_rules->time_to_eat);
	if (philo->forks[philo->name] == 0)
		philo->forks[philo->name]++;
	if (philo->forks[(philo->name + 1) % philo->sim_rules->nb_of_philos] == 0)
		philo->forks[(philo->name + 1) % philo->sim_rules->nb_of_philos]++;
	return (time);
}