/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bushra <bushra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 14:24:57 by bushra            #+#    #+#             */
/*   Updated: 2025/02/17 21:01:17 by bushra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	writing(t_info *info, int id, char *message)
{
	if (info->isdead != 1)
	{
		pthread_mutex_lock(&info->write_lock);
		printf("%ld", get_time() - info->birthdate);
		printf(" %d %s\n", id, message);
		pthread_mutex_unlock(&info->write_lock);
	}
}

int	eating(t_philos *philo, struct s_info *info)
{
	pthread_mutex_lock(philo->rfork);
	if (deadforever(info, philo) == 1)
	{
		pthread_mutex_unlock(philo->rfork);
		return (1);
	}
	writing(philo->info, philo->id, "has taken fork");
	if (info->nb_philos == 1)
	{
		pthread_mutex_unlock(philo->rfork);
		action_sleep(philo->info, info->t_die);
	}
	pthread_mutex_lock(philo->lfork);
	if (deadforever(info, philo) == 1)
	{
		pthread_mutex_unlock(philo->rfork);
		pthread_mutex_unlock(philo->lfork);
		return (1);
	}
	return (eating2(philo, info));
}

int	eating2(t_philos *philo, struct s_info *info)
{
	writing(philo->info, philo->id, "has taken fork");
	writing(philo->info, philo->id, "is eating");
	philo->t_last_meal = get_time();
	philo->eaten_meals++;
	if (action_sleep(philo->info, info->t_eat) == 1)
	{
		pthread_mutex_unlock(philo->rfork);
		pthread_mutex_unlock(philo->lfork);
		return (1);
	}
	pthread_mutex_unlock(philo->rfork);
	pthread_mutex_unlock(philo->lfork);
	return (0);
}
