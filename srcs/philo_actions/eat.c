/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seciurte <seciurte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 16:08:37 by seciurte          #+#    #+#             */
/*   Updated: 2022/01/18 18:11:44 by seciurte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	philo_eat(t_philo *philo)
{
	if (print_status(philo->name, THINK))
		return (-1);
	while (philo->forks[philo->name] == 0 ||
		philo->forks[(philo->name + 1) % philo->sim_rules->nb_of_philos] == 0);
	philo_take_fork(philo, philo->name);
	philo_take_fork(philo, (philo->name + 1) % philo->sim_rules->nb_of_philos);
	if (print_status(philo->name, EAT))
		return (-1);
	usleep(1000 * philo->sim_rules->time_to_eat);
	if (philo->forks[philo->name] == 0)
		philo->forks[philo->name]++;
	if (philo->forks[(philo->name + 1) % philo->sim_rules->nb_of_philos] == 0)
		philo->forks[(philo->name + 1) % philo->sim_rules->nb_of_philos]++;
	return (0);
}