/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bushra <bushra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 15:29:51 by bushra            #+#    #+#             */
/*   Updated: 2025/02/18 12:57:41 by bushra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int c, char **v)
{
	t_info	info;

	if (c == 6 || c == 5)
	{
		if (checkargs(v) == 1)
			return (0);
		ini(&info, v);
		initphilo(&info);
		if (create_threads(&info) == 1)
		{
			printf("ERROR: unable to create threads");
			return (0);
		}
	}
	else
		printf("ERROR: invalid number of arguments\n");
	return (0);
}
