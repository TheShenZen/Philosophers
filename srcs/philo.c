/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seciurte <seciurte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 23:53:00 by seciurte          #+#    #+#             */
/*   Updated: 2022/01/18 18:16:37 by seciurte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	set_sim_rules(t_sim_rules *sim_rules, char **av, int ac)
{
	sim_rules->nb_of_philos = ft_atoi(av[1]);
	sim_rules->time_to_die = ft_atoi(av[2]);
	sim_rules->time_to_eat = ft_atoi(av[3]);
	sim_rules->time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
		sim_rules->nb_of_cycles = ft_atoi(av[5]);
	else
		sim_rules->nb_of_cycles = 0;
	if (sim_rules->time_to_die < 0 ||sim_rules->time_to_eat < 0 ||
		sim_rules->time_to_sleep < 0 || sim_rules->nb_of_philos < 0 ||
		sim_rules->nb_of_cycles < 0)
		return (-1);
	sim_rules->nb_of_cycles = -1;
	sim_rules->stop = 0;
	return (0);
}

static void	check_for_dead_philos(t_philo *philo)
{
	int			i;

	i = 0;
	while (1)
	{
		if (is_dead(philo[i].sim_rules->time_to_die, philo[i].last_meal))
		{
			print_status(philo[i].name, DEAD);
			philo->sim_rules->stop = 1;
			break ;
		}
		i = (i + 1) % philo[i].sim_rules->nb_of_philos;
	}
}

static int	start_simulation(t_sim_rules *sim_rules, char **av, int ac)
{
	t_philo			*philos;

	philos = NULL;
	if (set_sim_rules(sim_rules, av, ac))
		return (-1);
	if (init_philos(&philos, sim_rules))
		return (-1);
	get_time();
	if (spwan_philos(sim_rules, philos))
		return (-1);
	check_for_dead_philos(philos);
	if (wait_for_philos(philos, sim_rules))
		return (-1);
	free(philos);
	return (0);
}

int	main(int ac, char **av)
{
	t_sim_rules		*sim_rules;

	if (check_args(ac, av))
	{
		printf("Error\n");
		return (-1);
	}
	sim_rules = malloc(sizeof(t_sim_rules));
	if (sim_rules == NULL)
	{
		printf("Error\n");
		return (-1);
	}
	if (start_simulation(sim_rules, av, ac))
	{
		printf("Error\n");
		free(sim_rules);
		return (-1);
	}
	free(sim_rules);
}
