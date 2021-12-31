/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seciurte <seciurte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 23:53:00 by seciurte          #+#    #+#             */
/*   Updated: 2021/12/31 15:58:33 by seciurte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *arg)
{
	(void) arg;
	printf("Philo has spawned !\n");
	sleep(1);
	return (NULL);
}

int	spwan_philoshophers(int nb_philos, int *philo_timers)
{
	t_philo		*philos;
	int			i;

	philos = malloc(sizeof(t_philo) * nb_philos + 1);
	if (philos == NULL)
		return (0);
	i = 0;
	while (i < nb_philos)
	{
		if (pthread_create(philos[i].philo, NULL, routine, NULL) != 0)
		{
			free(philos);
			printf("Error\n");
			return (0);
		}
		philos[i].name = i;
		philos[i].time_to_die = philo_timers[0];
		philos[i].time_to_eat = philo_timers[1];
		philos[i].time_to_sleep = philo_timers[2];
		i++;
	}
	return (1);
}

int	main(int ac, char **av)
{
	int		nb_philos;
	int		nb_cycles;
	int		philo_timers[3];

	if (ac == 5)
		nb_cycles = 0;
	else if (ac == 6)
		nb_cycles = ft_atoi(av[5]);
	else
	{
		printf("Wrong number of arguments.\n");
		return (-1);
	}
	nb_philos = ft_atoi(av[1]);
	philo_timers[0] = ft_atoi(av[2]);
	philo_timers[1] = ft_atoi(av[3]);
	philo_timers[2] = ft_atoi(av[4]);
	spwan_philoshophers(nb_philos, philo_timers);
}
