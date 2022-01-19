/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seciurte <seciurte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 16:33:37 by seciurte          #+#    #+#             */
/*   Updated: 2022/01/19 14:40:22 by seciurte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	philo_sleep(t_philo *philo)
{
	if (print_status(philo->name, SLEEP, philo))
		return (-1);
	usleep(1000 * philo->sim_rules->time_to_sleep);
	return (0);
}