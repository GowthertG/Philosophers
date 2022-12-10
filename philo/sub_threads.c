/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub_threads.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhaddouc <hhaddouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 23:20:23 by hhaddouc          #+#    #+#             */
/*   Updated: 2022/12/06 23:20:54 by hhaddouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	start_eating(t_philo *philo)
{
	int	fork_number;
	int	next_forki;

	fork_number = philo->philo_number - 1;
	next_forki = next_fork(philo);
	pthread_mutex_lock(&philo->global->fork[fork_number]);
	printf_lock(philo, "%d ms philosopher number %d has taken fork\n",
		get_time(philo->global->starter));
	pthread_mutex_lock(&philo->global->fork[next_forki]);
	printf_lock(philo, "%d ms philosopher number %d has taken fork\n",
		get_time(philo->global->starter));
	printf_lock(philo, "%d ms philosopher number %d is eating\n",
		get_time(philo->global->starter));
	ms_sleep(philo->global->time_to_eat);
	pthread_mutex_lock(philo->global->read_leat);
	philo->last_eat = get_time(philo->global->starter);
	pthread_mutex_unlock(philo->global->read_leat);
	if (philo->global->number_of_times_each_philosopher_must_eat != UNUSED)
		philo->meals++;
	pthread_mutex_lock(philo->global->meal);
	if (philo->meals
		== philo->global->number_of_times_each_philosopher_must_eat)
		philo->global->must_eat--;
	pthread_mutex_unlock(philo->global->meal);
	pthread_mutex_unlock(&philo->global->fork[fork_number]);
	pthread_mutex_unlock(&philo->global->fork[next_forki]);
}

void	ft_sleep(t_philo *philo)
{
	printf_lock(philo, "%d ms philosopher number %d is sleeping\n",
		get_time(philo->global->starter));
	ms_sleep(philo->global->time_to_sleep);
}

void	*routine(void *philo)
{
	t_philo	*c_philo;

	c_philo = (t_philo *)philo;
	while (1)
	{
		start_eating(c_philo);
		ft_sleep(c_philo);
		printf_lock(philo, "%d ms philosopher number %d is thinking\n",
			get_time(c_philo->global->starter));
	}
	return (NULL);
}

int	create_thread(t_philo *philo)
{
	int	index;

	philo->global->starter = get_time(0);
	index = 0;
	while (index < philo->global->number_of_philosophers)
	{
		pthread_create(philo[index].thread, NULL, &routine, &philo[index]);
		index += 2;
	}
	usleep(200);
	index = 1;
	while (index < philo->global->number_of_philosophers)
	{
		pthread_create(philo[index].thread, NULL, &routine, &philo[index]);
		index += 2;
	}
	return (0);
}
