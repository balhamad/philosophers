/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bushra <bushra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 14:36:20 by bushra            #+#    #+#             */
/*   Updated: 2025/02/17 14:41:14 by bushra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	checkdegit(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] > 57 || str[i] < 48)
			return (0);
		i++;
	}
	return (1);
}

int	checkargs(char **v)
{
	int	i;

	i = 1;
	while (i < 5)
	{
		if (ft_atoi(v[i]) <= 0 || checkdegit(v[i]) == 0)
		{
			printf("ERROR: invalid input\n");
			return (1);
		}
		i++;
	}
	if (v[5])
	{
		if (ft_atoi(v[5]) < 0 || checkdegit(v[5]) == 0)
		{
			printf("ERROR: invalid input\n");
			return (1);
		}
	}
	return (0);
}

int	ft_atoi(const char *nptr)

{
	int	i;
	int	sign;
	int	res;

	i = 0;
	res = 0;
	sign = 1;
	while (nptr[i] == ' ' || nptr[i] == '\t' || nptr[i] == '\n' \
			|| nptr[i] == '\v' || nptr[i] == '\f' || nptr[i] == '\r')
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign *= -1;
		i++;
	}
	while (nptr[i] <= '9' && nptr[i] >= '0')
	{
		res *= 10;
		res += nptr[i] - 48;
		i++;
	}
	return (sign * res);
}
