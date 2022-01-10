/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seciurte <seciurte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 23:53:00 by seciurte          #+#    #+#             */
/*   Updated: 2022/01/10 16:58:52 by seciurte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	set_sim_rules(t_sim_rules *sim_rules, char **av)
{
	sim_rules->nb_of_philos = ft_atoi(av[1]);
	sim_rules->time_to_die = ft_atoi(av[1]);
	sim_rules->time_to_eat = ft_atoi(av[1]);
	sim_rules->time_to_sleep = ft_atoi(av[1]);
	if (sim_rules->time_to_die < 0 ||sim_rules->time_to_eat < 0 ||
		sim_rules->time_to_sleep < 0 || sim_rules->nb_of_philos < 0)
		return (-1);
	return (0);
}

static int	start_simulation(t_sim_rules *sim_rules, char **av)
{
	t_philo			*philos;

	if (set_sim_rules(sim_rules, av))
		return (-1);
	get_time();
	if (spwan_philos(sim_rules, &philos))
		return (-1);
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
	if (start_simulation(sim_rules, av))
	{
		printf("Error\n");
		free(sim_rules);
		return (-1);
	}
	free(sim_rules);
}
