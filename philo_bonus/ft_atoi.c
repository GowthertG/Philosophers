/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhaddouc <hhaddouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 20:13:51 by hhaddouc          #+#    #+#             */
/*   Updated: 2022/12/05 21:18:16 by hhaddouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(const char *str)
{
	int		sign;
	long	res;

	sign = 1;
	res = 0;
	while ((*str >= 9 && *str <= 13) || *str == ' ')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = sign * -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		if (res * 10 + (*str - 48)
			> (long )2147483647 && sign == 1)
			return (error("invalid arguments") % 1);
		else if (res * 10 + (*str - 48)
			> (long )2147483647 + 1 && sign == -1)
			return (error("invalid arguments") % 1);
		res = res * 10 + (*str - 48);
		str++;
	}
	return (res * sign);
}
