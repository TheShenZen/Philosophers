/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seciurte <seciurte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 15:14:13 by seciurte          #+#    #+#             */
/*   Updated: 2022/01/18 15:19:32 by seciurte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_strlen(char *str)
{
	int			i;

	if (str == NULL)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

static int	nbrlen(long nbr)
{
	int	len;

	len = 1;
	nbr /= 10;
	while (nbr != 0)
	{
		len++;
		nbr /= 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	int		len;
	long	nbr;
	char	*str;

	nbr = (long)n;
	len = nbrlen(nbr) + 1;
	if (nbr < 0)
		len = nbrlen(nbr * -1) + 2;
	str = malloc(sizeof(char) * len);
	if (str == NULL)
		return (NULL);
	memset(str, '\0', len);
	if (nbr < 0)
	{
		str[0] = '-';
		nbr *= -1;
	}
	len -= 2;
	while (len >= 0 && str[len] != '-')
	{
		str[len] = nbr % 10 + '0';
		nbr /= 10;
		len--;
	}
	return (str);
}

int	ft_strncmp(char *s1, char *s2, size_t n)
{
	unsigned char	c1;
	unsigned char	c2;
	size_t			l1;
	size_t			l2;
	size_t			i;

	if (n == 0)
		return (0);
	i = 0;
	l1 = ft_strlen(s1);
	l2 = ft_strlen(s2);
	while (i <= l1 && i <= l2 && i < n)
	{
		c1 = (unsigned char)s1[i];
		c2 = (unsigned char)s2[i];
		i++;
		if (c1 != c2)
			return (c1 - c2);
	}
	return (0);
}
