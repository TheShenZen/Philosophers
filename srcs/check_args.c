/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seciurte <seciurte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 12:31:30 by seciurte          #+#    #+#             */
/*   Updated: 2022/01/18 15:28:34 by seciurte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

static int	is_empty(char *str)
{
	int		i;

	i = 0;
	if (ft_strlen(str) == 0)
		return (1);
	while (str[i])
	{
		if (ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

static int	is_all_digit(char *str)
{
	int			i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]) && str[i] != ' ' && str[i] != '-')
			return (0);
		i++;
	}
	return (1);
}

static int	check_overflow(char *val)
{
	char		*tmp_s;
	int			tmp_i;

	tmp_i = 0;
	tmp_s = NULL;
	tmp_i = ft_atoi(val);
	tmp_s = ft_itoa(tmp_i);
	if (tmp_s == NULL)
		return (1);
	if (ft_strncmp(tmp_s, val, ft_strlen(tmp_s)) != 0)
	{
		free(tmp_s);
		return (1);
	}
	free(tmp_s);
	return (0);
}

int	check_args(int ac, char **av)
{
	int			i;

	if (ac != 5 && ac != 6)
		return (-1);
	i = 1;
	while (i < 5)
	{
		if (is_empty(av[i]))
			return (-1);
		if (!is_all_digit(av[i]))
			return (-1);
		if (check_overflow(av[i]))
			return (-1);
		i++;
	}
	if (ac == 6)
	{
		if (is_empty(av[i]))
			return (-1);
		if (!is_all_digit(av[i]))
			return (-1);
		if (check_overflow(av[i]))
			return (-1);
	}
	return (0);
}