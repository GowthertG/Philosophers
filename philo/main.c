/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhaddouc <hhaddouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 20:13:33 by hhaddouc          #+#    #+#             */
/*   Updated: 2022/12/06 22:58:35 by hhaddouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_philo	*philo;

	(void)(argc);
	if (check_args(argv) || check_value(argv))
		return (error ("invalid argument"));
	philo = init_philosophers(argv);
  create_thread(philo);
	return (third_eye(philo));
}
