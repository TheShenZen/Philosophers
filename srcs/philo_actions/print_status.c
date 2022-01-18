/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_status.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seciurte <seciurte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 16:24:33 by seciurte          #+#    #+#             */
/*   Updated: 2022/01/18 18:18:53 by seciurte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	print_status(int name, int msg)
{
	static pthread_mutex_t		padlock;
	static int					flag;
	long						time;

	if (flag == 0)
	{
		if (pthread_mutex_init(&padlock, NULL))
			return (-1);
		flag = 1;
	}
	pthread_mutex_lock(&padlock);
	time = get_time();
	if (msg == 0)
		printf("%ld %d is thinking\n", time, name);
	else if (msg == 1)
		printf("%ld %d has taken a fork\n", time, name);
	else if (msg == 2)
		printf("%ld %d is eating\n", time, name);
	else if (msg == 3)
		printf("%ld %d is sleeping\n", time, name);
	else
		printf("%ld %d died\n", time, name);
	pthread_mutex_unlock(&padlock);
	return (0);
}