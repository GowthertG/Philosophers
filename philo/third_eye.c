/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   third_eye.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhaddouc <hhaddouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 01:30:48 by hhaddouc          #+#    #+#             */
/*   Updated: 2022/12/06 23:12:19 by hhaddouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	third_eye(t_philo *philosophers)
{
	int	index;
	int	return_value;

	index = 0;
	while (1)
	{
		while (index < philosophers->global->number_of_philosophers)
		{
			return_value = check_meals(&philosophers[index]);
			if (return_value != 0)
				return (return_value);
			index++;
		}
		index = 0;
	}
}

int	check_meals(t_philo *philo)
{
	pthread_mutex_lock(philo->global->read_leat);
	if ((get_time(philo->global->starter) - philo->last_eat) >= philo->global->time_to_die)
	{
		pthread_mutex_lock(philo->global->msg);
		printf("%ld ms philo %d is dead\n",
			get_time(philo->global->starter), philo->philo_number);
		return (FALSE);
	}
	pthread_mutex_unlock(philo->global->read_leat);
  pthread_mutex_lock(philo->global->meal);
	if (philo->global->number_of_times_each_philosopher_must_eat != UNUSED
		&& philo->global->must_eat == 0)
	{
		pthread_mutex_lock(philo->global->msg);
		return (FULL);
	}
	pthread_mutex_unlock(philo->global->meal);
	return (0);
}

int	min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}
