/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seciurte <seciurte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 16:08:37 by seciurte          #+#    #+#             */
/*   Updated: 2022/01/19 18:50:21 by seciurte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	take_forks(t_philo *philo)
{
	while (philo_take_fork(philo, philo->name) == 0 && !terminate(philo))
		;
	while (philo_take_fork(philo,
			(philo->name + 1) % philo->sim_rules->nb_of_philos) == 0
		&& !terminate(philo))
		;
	return (0);
}

int	philo_eat(t_philo *philo)
{
	int			time;
	int			sp;

	if (print_status(philo->name, THINK, philo))
		return (-1);
	if (take_forks(philo))
		return (-1);
	if (print_status(philo->name, EAT, philo))
		return (-1);
	time = get_time();
	pthread_mutex_lock(&philo->sim_rules->mtx);
	sp = philo->sim_rules->time_to_sleep;
	pthread_mutex_unlock(&philo->sim_rules->mtx);
	usleep(1000 * philo->sim_rules->time_to_eat);
	pthread_mutex_lock(&philo->mtx[philo->name]);
	if (philo->forks[philo->name] == 0)
		philo->forks[philo->name]++;
	pthread_mutex_unlock(&philo->mtx[philo->name]);
	pthread_mutex_lock(
		&philo->mtx[(philo->name + 1) % philo->sim_rules->nb_of_philos]);
	if (philo->forks[(philo->name + 1) % philo->sim_rules->nb_of_philos] == 0)
		philo->forks[(philo->name + 1) % philo->sim_rules->nb_of_philos]++;
	pthread_mutex_unlock(
		&philo->mtx[(philo->name + 1) % philo->sim_rules->nb_of_philos]);
	return (time);
}
