/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bushra <bushra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 14:21:59 by bushra            #+#    #+#             */
/*   Updated: 2025/02/17 14:24:23 by bushra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

size_t	get_time(void)
{
	size_t			milliseconds;
	struct timeval	te;

	if (gettimeofday(&te, NULL) == -1)
		write(2, "error in time\n", 15);
	milliseconds = ((te.tv_sec * 1000) + te.tv_usec / 1000);
	return (milliseconds);
}

int	action_sleep(t_info *info, size_t action_time)
{
	size_t	start;

	start = get_time();
	while (((get_time() - start) < action_time))
	{
		if (deadforever(info, info->philo) == 1)
		{
			return (1);
		}
		usleep(500);
	}
	return (0);
}
