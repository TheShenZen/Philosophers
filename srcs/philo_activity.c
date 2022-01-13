/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_activity.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seciurte <seciurte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 16:22:35 by seciurte          #+#    #+#             */
/*   Updated: 2022/01/13 20:14:43 by seciurte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


int	manage_activity(t_philo *philo)
{
	int					last_activity;
	int					last_meal;
	int					status;

	philo = (t_philo *)arg;
	last_activity = get_time();
	last_meal = get_time();
	status = philo->name % 3;
	while (philo->nb_of_cycles)
	{
		
		usleep(450);
		if (philo->nb_of_cycles > 0)
			philo->nb_of_cycles--;
	}
}