/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seciurte <seciurte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 23:53:00 by seciurte          #+#    #+#             */
/*   Updated: 2022/01/19 18:47:25 by seciurte         ###   ########.fr       */
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
		sim_rules->nb_of_cycles = -1;
	if (sim_rules->time_to_die < 0 || sim_rules->time_to_eat < 0
		|| sim_rules->time_to_sleep < 0 || sim_rules->nb_of_philos <= 0
		|| (sim_rules->nb_of_cycles < 0 && ac == 6))
		return (-1);
	sim_rules->stop = 0;
	pthread_mutex_init(&sim_rules->mtx, NULL);
	return (0);
}

static void	free_all(t_philo *philo)
{
	int			i;

	i = 0;
	while (i < philo->sim_rules->nb_of_philos)
	{
		pthread_mutex_destroy(&philo[i].mtx[i]);
		i++;
	}
	pthread_mutex_destroy(&philo->sim_rules->mtx);
	free(philo->forks);
	free(philo->mtx);
	free(philo->sim_rules);
	free(philo);
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
	if (wait_for_philos(philos, sim_rules))
		return (-1);
	free_all(philos);
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
}
