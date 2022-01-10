/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seciurte <seciurte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 16:55:39 by seciurte          #+#    #+#             */
/*   Updated: 2022/01/10 17:12:19 by seciurte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_forks(int *forks, t_sim_rules *sim_rules)
{
	int			i;

	forks = malloc(sizeof(int) * sim_rules->nb_of_philos);
	if (forks == NULL)
		return (-1);
	i = 0;
	while(i < sim_rules->nb_of_philos)
	{
		forks[i] = 1;
		i++;
	}
}
int	init_padlocks(pthread_mutex_t *padlocks, t_sim_rules *sim_rules)
{
	int			i;

	padlocks = malloc(sizeof(pthread_mutex_t) * sim_rules->nb_of_philos);
	if (padlocks == NULL)
		return (-1);
	i = 0;

}

int	init_philos(t_philo *philos, t_sim_rules *sim_rules)
{
	int				i;

	philos = malloc(sizeof(t_philo) * sim_rules->nb_of_philos);
	if (philos == NULL)
		return (-1);
	if (init_padlocks())
		return (-1);
	init_forks(philos->forks, sim_rules);
	i = 0;
	while (i < sim_rules)
	{
		philos[i].name = i;
		philos[i].nb_of_cycles = sim_rules->nb_of_cycles;
		philos[i].sim_rules = sim_rules;
		philos[i].forks = philos->forks;
	}
}