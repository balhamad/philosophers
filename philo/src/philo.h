/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bushra <bushra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 15:12:19 by bushra            #+#    #+#             */
/*   Updated: 2025/02/17 15:20:26 by bushra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <sys/time.h>
# include <pthread.h>
# include <stdlib.h>

typedef struct s_philos
{
	struct s_info	*info;
	pthread_mutex_t	*rfork;
	pthread_mutex_t	*lfork;
	pthread_t		thread;
	size_t			t_last_meal;
	int				id;
	int				eating;
	int				eaten_meals;
}	t_philos;

typedef struct s_info
{
	pthread_mutex_t	meal_lock;
	pthread_mutex_t	write_lock;
	pthread_mutex_t	eat_lock;
	pthread_mutex_t	dead_lock;
	pthread_mutex_t	forks[202];
	t_philos		philo[202];
	size_t			birthdate;
	int				nb_philos;
	int				t_die;
	int				t_eat;
	int				t_sleep;
	int				nb_meals;
	int				isdead;
}	t_info;

int		checkdegit(char *str);
int		ft_atoi(const char *nptr);
int		checkargs(char **v);
int		ft_strlen(char *str);
int		eating(t_philos *philo, struct s_info *info);
int		eating2(t_philos *philo, struct s_info *info);
void	writing(t_info *info, int id, char *message);
void	*thread(void *philo);
int		isdead(t_philos *philo);
size_t	get_time(void);
void	ini(t_info *info, char **v);
void	initphilo(t_info *info);
int		create_threads(t_info *info);
int		action_sleep(t_info *info, size_t action_time);
int		deadforever(t_info *info, t_philos *philo);
int		alldead(t_info *info, t_philos *philo);

#endif
