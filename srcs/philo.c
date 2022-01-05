/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seciurte <seciurte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 23:53:00 by seciurte          #+#    #+#             */
/*   Updated: 2022/01/05 18:37:07 by seciurte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	start_simulation(t_sim_rules *sim_rules)
{
	t_philo		*philos;

	get_time();
	if (spwan_philos(sim_rules, &philos))
		return (-1);
	give_philos_the_rules(&philos, sim_rules);
	if (wait_for_philos(&philos, sim_rules))
		return (-1);
	free(philos);
	return (0);
}

int	main(int ac, char **av)
{
	t_sim_rules		*sim_rules;

	sim_rules = malloc(sizeof(t_sim_rules));
	if (sim_rules == NULL)
	{
		printf("Error\n");
		return (-1);
	}
	if (ac == 5)
		sim_rules->nb_of_cycles = -1;
	else if (ac == 6)
		sim_rules->nb_of_cycles = ft_atoi(av[5]);
	else
	{
		printf("Error\n");
		return (-1);
	}
	sim_rules->nb_of_philos = ft_atoi(av[1]);
	sim_rules->time_to_die = ft_atoi(av[1]);
	sim_rules->time_to_eat = ft_atoi(av[1]);
	sim_rules->time_to_sleep = ft_atoi(av[1]);
	start_simulation(sim_rules);
	free(sim_rules);
}
