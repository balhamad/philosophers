/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dead.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bushra <bushra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 14:03:30 by bushra            #+#    #+#             */
/*   Updated: 2025/02/17 20:43:49 by bushra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	deadforever(t_info *info, t_philos *philo)
{
	size_t	n;

	n = info->t_die;
	if (get_time() - philo->t_last_meal >= n)
	{
		pthread_mutex_lock(&info->dead_lock);
		writing(info, philo->id, "died");
		info->isdead = 1;
		pthread_mutex_unlock(&info->dead_lock);
		return (1);
	}
	pthread_mutex_lock(&info->dead_lock);
	if (info->isdead)
	{
		pthread_mutex_unlock(&info->dead_lock);
		return (1);
	}
	pthread_mutex_unlock(&info->dead_lock);
	return (0);
}
