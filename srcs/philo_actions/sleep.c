/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seciurte <seciurte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 16:33:37 by seciurte          #+#    #+#             */
/*   Updated: 2022/01/17 09:50:03 by seciurte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	philo_sleep(t_philo *philo)
{
	long		time;

	time = get_time();
	printf("%ld %d is sleeping\n", time, philo->name);
	usleep(1000 * philo->sim_rules->time_to_sleep);
	return (time);
}