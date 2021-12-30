/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seciurte <seciurte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 23:53:00 by seciurte          #+#    #+#             */
/*   Updated: 2021/12/31 00:28:07 by seciurte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	int		nb_philo;
	int		nb_cycles;

	if (ac == 6)
	{
		nb_philo = ft_atoi(av[1]);
		nb_cycles = 0;
	}
	else if (ac == 7)
	{
		nb_philo = ft_atoi(av[1]);
		nb_cycles = 0;
	}
	else
	{
		printf("Wrong number of arguments.\n");
		return (-1);
	}
}