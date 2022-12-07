/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhaddouc <hhaddouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 22:37:16 by hhaddouc          #+#    #+#             */
/*   Updated: 2022/12/06 23:19:32 by hhaddouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ms_sleep(int ms)
{
	long	count;

	count = get_time(0);
	while (get_time(count) < ms)
		usleep(300);
}

long	get_time(long ms)
{
	struct timeval	current_time;

	gettimeofday (&current_time, NULL);
	return (((current_time.tv_sec * 1000)
			+ (current_time.tv_usec / 1000)) - ms);
}

void	printf_lock(t_philo *philo, char *str, long time)
{
	pthread_mutex_lock (philo->global->msg);
	printf (str, (int)time, philo->philo_number);
	pthread_mutex_unlock (philo->global->msg);
}

int	next_fork(t_philo *philo)
{
	if (philo->philo_number == philo->global->number_of_philosophers)
		return (0);
	else
		return (philo->philo_number);
}

