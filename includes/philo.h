/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seciurte <seciurte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 23:51:09 by seciurte          #+#    #+#             */
/*   Updated: 2022/01/03 16:58:12 by seciurte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_philo
{
	pthread_t	philo;
	int			name;
}				t_philo;

typedef struct s_sim_rules
{
	int					time_to_die;
	int					time_to_eat;
	int					time_to_sleep;
	int					nb_of_cycles;
	int					nb_of_forks;
	pthread_mutex_t		padlock;
}				t_sim_rules;


int		ft_atoi(const char *nptr);

#endif