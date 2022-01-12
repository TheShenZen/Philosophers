/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_sim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seciurte <seciurte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 18:35:51 by seciurte          #+#    #+#             */
/*   Updated: 2022/01/12 16:35:59 by seciurte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*start_work(void *arg)
{
	t_philo				*philo;
	int					last_activity;
	int					last_meal;
	int					status;

	philo = (t_philo *)arg;
	while (philo->nb_of_cycles)
	{
		usleep(450);
		philo->nb_of_cycles--;
	}
	return (NULL);
}
