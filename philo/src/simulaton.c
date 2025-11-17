/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulaton.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bushra <bushra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 14:12:48 by bushra            #+#    #+#             */
/*   Updated: 2025/02/17 20:31:38 by bushra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*thread(void *po)
{
	t_philos	*philo;

	philo = (t_philos *)po;
	if ((philo->id) % 2 == 0)
		usleep(500);
	while (!philo->info->isdead)
	{
		writing(philo->info, philo->id, "is thinking");
		if (deadforever(philo->info, philo))
			break ;
		if (eating(philo, philo->info) == 1)
			break ;
		if (philo->eaten_meals == philo->info->nb_meals)
			break ;
		if (philo->info->isdead == 1)
			break ;
		if (deadforever(philo->info, philo) == 1)
			break ;
		writing(philo->info, philo->id, "is sleeping");
		if (action_sleep(philo->info, philo->info->t_sleep) == 1)
			break ;
	}
	return (po);
}

int	create_threads(t_info *info)
{
	int	i;

	i = 0;
	while (i < info->nb_philos)
	{
		if (pthread_create(&info->philo[i].thread, NULL, \
			&thread, &info->philo[i]) != 0)
			return (1);
		i++;
	}
	i = 0;
	while (i < info->nb_philos)
	{
		if (pthread_join(info->philo[i].thread, NULL) != 0)
			return (1);
		i++;
	}
	return (0);
}
