/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_sim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seciurte <seciurte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 18:35:51 by seciurte          #+#    #+#             */
/*   Updated: 2022/01/05 18:37:04 by seciurte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	print_status(t_philo *philo)
{
	pthread_mutex_t		padlock;
	long				time;

	if (pthread_mutex_init(&padlock, NULL))
		return (-1);
	pthread_mutex_lock(&padlock);
	pthread_mutex_unlock(&padlock);
	pthread_mutex_destroy(&padlock);
	return (0);
}

void	*start_work(void *arg)
{
	t_philo				*philo;
	int					i;

	philo = (t_philo *)arg;
	i = 0;
	while (i < philo->nb_of_cycles)
	{
		print_status(philo);
		usleep(450);
		i++;
	}
	return (NULL);
}