/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhaddouc <hhaddouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 20:14:18 by hhaddouc          #+#    #+#             */
/*   Updated: 2022/12/06 22:41:24 by hhaddouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_value(char **numbers)
{
	int	index;

	index = 1;
	while (numbers[index])
	{
		if (ft_atoi(numbers[index]) <= 0)
			return (1);
		index++;
	}
	return (0);
}

int	check_args(char **argv)
{
	int	index;
	int	j;

	index = 1;
	while (argv[index])
	{
		j = 0;
		while (argv[index][j])
		{
			if (argv[index][j] >= '0' && argv[index][j] <= '9')
			j++;
			else
				return (1);
		}
				index++;
	}
	return (0);
}

t_list	*init_global(char **args)
{
	t_list	*global;

	global = malloc(sizeof (t_list));
	global->number_of_philosophers = ft_atoi(args[1]);
	global->time_to_die = ft_atoi(args[2]);
	global->time_to_eat = ft_atoi(args[3]);
	global->time_to_sleep = ft_atoi(args[4]);
	global->fork = malloc ((sizeof (pthread_mutex_t)
				* global->number_of_philosophers));
	global->msg = malloc(sizeof(pthread_mutex_t));
	global->meal = malloc(sizeof(pthread_mutex_t));
	global->read_leat = malloc(sizeof(pthread_mutex_t));
	pthread_mutex_init(global->read_leat, NULL);
	pthread_mutex_init(global->msg, NULL);
	pthread_mutex_init(global->meal, NULL);
	if (args[5])
	{
		global->number_of_times_each_philosopher_must_eat = ft_atoi(args[5]);
		global->must_eat = global->number_of_philosophers;
	}
	else
	{
		global->number_of_times_each_philosopher_must_eat = UNUSED;
    global->must_eat = UNUSED;
	}
	return (global);
}

int	error(char *error)
{
	return (printf ("Error : %s\n", error));
}

t_philo	*init_philosophers(char **args)
{
	t_philo	*tmp;
	t_list	*global_tmp;
	int		index;

	tmp = malloc(sizeof (t_philo) * ft_atoi(args[1]));
	global_tmp = init_global(args);
	index = 0;
	while (index < ft_atoi(args[1]))
	{
		tmp[index].meals = 0;
		tmp[index].philo_number = index + 1;
		tmp[index].global = global_tmp;
		tmp[index].thread = malloc(sizeof(pthread_t));
		tmp[index].last_eat = 0;
		pthread_mutex_init(&tmp->global->fork[index], NULL);
		index++;
	}
	return (tmp);
}
