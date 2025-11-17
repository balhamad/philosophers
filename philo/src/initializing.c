/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bushra <bushra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 14:30:19 by bushra            #+#    #+#             */
/*   Updated: 2025/02/17 14:31:32 by bushra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ini(t_info *info, char **v)
{
	int	i;

	i = 0;
	info->nb_philos = ft_atoi(v[1]);
	while (i < info->nb_philos)
	{
		info->forks[i] = (pthread_mutex_t)PTHREAD_MUTEX_INITIALIZER;
		i++;
	}
	info->t_die = ft_atoi(v[2]);
	info->t_eat = ft_atoi(v[3]);
	info->t_sleep = ft_atoi(v[4]);
	info->isdead = 0;
	info->birthdate = get_time();
	info->meal_lock = (pthread_mutex_t)PTHREAD_MUTEX_INITIALIZER;
	info->write_lock = (pthread_mutex_t)PTHREAD_MUTEX_INITIALIZER;
	info->eat_lock = (pthread_mutex_t)PTHREAD_MUTEX_INITIALIZER;
	info->dead_lock = (pthread_mutex_t)PTHREAD_MUTEX_INITIALIZER;
	if (v[5])
		info->nb_meals = ft_atoi(v[5]);
	else
		info->nb_meals = -1;
}

void	initphilo(t_info *info)
{
	int	i;

	i = 0;
	while (i < info->nb_philos)
	{
		info->philo[i].id = i + 1;
		info->philo[i].eating = 0;
		info->philo[i].eaten_meals = 0;
		info->philo[i].t_last_meal = get_time();
		info->philo[i].lfork = &info->forks[i];
		info->philo[i].rfork = &info->forks[(i + 1) % info->nb_philos];
		info->philo[i].info = info;
		i++;
	}
}
