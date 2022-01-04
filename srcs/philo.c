/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seciurte <seciurte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 23:53:00 by seciurte          #+#    #+#             */
/*   Updated: 2022/01/04 18:44:56 by seciurte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	start_work(void *arg)
{
	printf("I am alive!");
	return (NULL);
}

static int	spwan_philos(t_sim_rules *sim_rules, t_philo **philos)
{
	int			i;

	(*philos) = malloc(sizeof(t_philo) * sim_rules->nb_of_philos + 1);
	if ((*philos) == NULL)
		return (-1);
	i = 0;
	while (i < sim_rules->nb_of_philos)
	{
		if (pthread_create(&((*philos)[i].philo), NULL, start_work, *philos))
		{
			free((*philos));
			return (-1);
		}
		if (pthread_mutex_init(&((*philos)[i].mtx), NULL))
		{
			free((*philos));
			return (-1);
		}
		(*philos)[i].name = i;
		(*philos)[i].nb_of_cycles = sim_rules->nb_of_cycles;
		i++;
	}
	(*philos)[i] = NULL;
	return (0);
}

static void	give_philos_the_rules(t_philo **philos, t_sim_rules *sim_rules)
{
	int		i;

	i = 0;
	while ((*philos)[i])
	{
		(*philos)[i].time_to_die = sim_rules->time_to_die;
		(*philos)[i].time_to_eat = sim_rules->time_to_eat;
		(*philos)[i].time_to_sleep = sim_rules->time_to_sleep;
		i++;
	}
}

static int	start_simulation(t_sim_rules *sim_rules)
{
	t_philo		*philos;

	if (spwan_philos(sim_rules, &philos))
		return (-1);
	give_philos_the_rules(&philos, sim_rules);
	return (0);
}

int	main(int ac, char **av)
{
	t_sim_rules		*sim_rules;

	sim_rules = malloc(sizeof(t_sim_rules));
	if (sim_rules = NULL)
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
}
