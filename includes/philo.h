/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seciurte <seciurte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 23:51:09 by seciurte          #+#    #+#             */
/*   Updated: 2022/01/14 15:46:47 by seciurte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_sim_rules
{
	int					time_to_die;
	int					time_to_eat;
	int					time_to_sleep;
	int					nb_of_cycles;
	int					nb_of_philos;
}				t_sim_rules;

typedef struct s_philo
{
	int					name;
	int					nb_of_cycles;
	int					*forks;
	t_sim_rules			*sim_rules;
	struct s_philo		*philos;
	pthread_t			philo;
	pthread_mutex_t		*mtx;
}				t_philo;

int		ft_atoi(const char *nptr);
long	get_time(void);
int		init_philos(t_philo **philos, t_sim_rules *sim_rules);
int		spwan_philos(t_sim_rules *sim_rules, t_philo *philos);
int		wait_for_philos(t_philo *philos, t_sim_rules *sim_rules);
int		print_status(t_philo *philo);
void	*start_work(void *arg);
int		philo_sleep(t_philo *philo);
int		philo_think(t_philo *philo);
int		philo_take_fork(t_philo *philo, int fork);
int		philo_eat(t_philo *philo);
int		manage_activity(t_philo *philo);

#endif