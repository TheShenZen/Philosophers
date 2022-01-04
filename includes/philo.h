/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seciurte <seciurte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 23:51:09 by seciurte          #+#    #+#             */
/*   Updated: 2022/01/04 18:40:40 by seciurte         ###   ########.fr       */
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
	pthread_t			philo;
	int					name;
	int					nb_of_cycles;
	int					time_to_die;
	int					time_to_eat;
	int					time_to_sleep;
	int					fork;
	pthread_mutex_t		mtx;
}				t_philo;

typedef struct s_sim_rules
{
	int					time_to_die;
	int					time_to_eat;
	int					time_to_sleep;
	int					nb_of_cycles;
	int					nb_of_philos;
}				t_sim_rules;


int		ft_atoi(const char *nptr);

#endif