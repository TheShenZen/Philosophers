/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seciurte <seciurte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 23:51:09 by seciurte          #+#    #+#             */
/*   Updated: 2022/01/19 14:44:03 by seciurte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

# define THINK 0
# define FORK 1
# define EAT 2
# define SLEEP 3

typedef struct s_sim_rules
{
	int					time_to_die;
	int					time_to_eat;
	int					time_to_sleep;
	int					nb_of_cycles;
	int					nb_of_philos;
	int					stop;
}				t_sim_rules;

typedef struct s_philo
{
	int					name;
	int					last_meal;
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
void	*start_work(void *arg);
int		philo_sleep(t_philo *philo);
int		philo_think(t_philo *philo);
int		philo_take_fork(t_philo *philo, int fork);
int		philo_eat(t_philo *philo);
int		is_dead(int time_to_die, int last_meal);
int		check_args(int ac, char **av);
int		ft_strlen(char *str);
char	*ft_itoa(int n);
int		ft_strncmp(char *s1, char *s2, size_t n);
int		print_status(int name, int msg, t_philo *philo);


#endif