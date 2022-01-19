/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_status.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seciurte <seciurte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 16:24:33 by seciurte          #+#    #+#             */
/*   Updated: 2022/01/19 18:47:45 by seciurte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	check_for_dead_philos(t_philo *philo)
{
	pthread_mutex_lock(&philo->sim_rules->mtx);
	if (is_dead(philo->sim_rules->time_to_die, philo->last_meal)
		&& philo->sim_rules->stop == 0)
	{
		printf("%ld %d died\n", get_time(), philo->name);
		philo->sim_rules->stop = 1;
	}
	pthread_mutex_unlock(&philo->sim_rules->mtx);
}

static void	printf_msg(long time, int name, int msg)
{
	if (msg == 0)
		printf("%ld %d is thinking\n", time, name);
	else if (msg == 1)
		printf("%ld %d has taken a fork\n", time, name);
	else if (msg == 2)
		printf("%ld %d is eating\n", time, name);
	else if (msg == 3)
		printf("%ld %d is sleeping\n", time, name);
}

int	print_status(int name, int msg, t_philo *philo)
{
	long						time;

	check_for_dead_philos(philo);
	pthread_mutex_lock(&philo->sim_rules->mtx);
	if (philo->sim_rules->stop)
	{
		pthread_mutex_unlock(&philo->sim_rules->mtx);
		return (0);
	}
	time = get_time();
	printf_msg(time, name, msg);
	pthread_mutex_unlock(&philo->sim_rules->mtx);
	return (0);
}
