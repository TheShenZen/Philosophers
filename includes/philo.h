/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seciurte <seciurte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 23:51:09 by seciurte          #+#    #+#             */
/*   Updated: 2021/12/31 15:59:52 by seciurte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

# define	IS_DEAD 0001
# define	IS_EATING 0010
# define	IS_SLEEPING 0100
# define	IS_THINKING 1000

typedef struct s_philo
{
	pthread_t	philo;
	int			name;
	int			time_to_die;
	int			time_to_eat;
	int			time_to_sleep;
	int			fork;
	char		status;
}				t_philo;

int		ft_atoi(const char *nptr);

#endif