/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seciurte <seciurte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 23:53:00 by seciurte          #+#    #+#             */
/*   Updated: 2022/01/03 16:44:39 by seciurte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *arg)
{
	pthread_mutex_t		*mtx;

	mtx = (pthread_mutex_t *)arg;
	while (1)
	{
		printf("is eating !\n");
	}
	return (NULL);
}

int	spwan_philoshophers(int nb_philos, int *philo_timers, pthread_mutex_t *mtx)
{
	pthread_t		*philos;
	int			i;

	philos = malloc(sizeof(pthread_t) * nb_philos + 1);
	if (philos == NULL)
		return (1);
	i = 0;
	while (i < nb_philos)
	{
		if (pthread_create(&philos[i],
			NULL, routine, (void *) mtx) != 0)
		{
			free(philos);
			printf("Error\n");
			return (1);
		}
		i++;
	}
	for (int i = 0; i < 10; i++)
	{
		pthread_join(philos[i], NULL);
	}
	return (0);
}

static int	run_philo_sim(int nb_phs, int *phs_timers, pthread_mutex_t *mtx)
{
	if (pthread_mutex_init(mtx, NULL) != 0)
	{
		printf("Error\n");
		return (-1);
	}
	if (spwan_philoshophers(nb_phs, phs_timers, mtx) != 0)
	{
		printf("Error\n");
		return (-1);
	}
	return (0);
}

int	main(int ac, char **av)
{

	pthread_mutex_t		mtx;

	if (ac == 5)
		nb_cycles = 0;
	else if (ac == 6)
		nb_cycles = ft_atoi(av[5]);
	else
	{
		printf("Wrong number of arguments.\n");
		return (-1);
	}
	if (run_philo_sim(nb_philos, philo_timers, &mtx))
	{
		printf("Error\n");
		return (-1);
	}
	pthread_mutex_destroy(&mtx);
}
