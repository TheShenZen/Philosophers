/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_death.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seciurte <seciurte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 16:59:01 by seciurte          #+#    #+#             */
/*   Updated: 2022/01/19 14:44:42 by seciurte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	is_dead(int time_to_die, int last_meal)
{
	long		time;

	time = get_time();
	if (time - last_meal > time_to_die)
		return (1);
	return (0);
}
