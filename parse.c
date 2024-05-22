/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izperez <izperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 11:43:26 by izperez           #+#    #+#             */
/*   Updated: 2024/05/22 13:46:30 by izperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/* 1. Check negatives
 * 2. Check rare symbols
 * 3. Check INT_MAX/MIN
 */
static const char	*valid_input(const char *str)
{
	int			len;
	const char	*num;

	len = 0;
	while (ft_isspace(*str))
		str++;
	if (*str == '+')
		str++;
	else if (*str == '-')
		print_exit("Error invalid negative num");
	if (!ft_isdigit(*str))
		print_exit("Error, only digit values");
	num = str;
	while (ft_isdigit(*str++))
		len++;
	if (len > 10)
		print_exit("Error");
	return (num);
}

static long	new_atol(const char *str)
{
	long	num;

	num = 0;
	str = valid_input(str);
	while (ft_isdigit(*str))
	{
		num = (num *  10) + (*str - '0');
		str++;
	}
	if (num > INT_MAX || num < INT_MIN)
		print_exit("Int max/min");
	return (num);
}

/* 1. Numbers
 * 2. Int max
 * 3. Timestamp > 60ms */
void	error_check(t_table *table, char **av)
{
	table->nbr_philo = new_atol(av[1]);
	table->time_to_die = new_atol(av[2]) * 1000;
	table->time_to_eat = new_atol(av[3]) * 1000;
	table->time_to_sleep = new_atol(av[4]) * 1000;
	if (table->time_to_die < 60000 || table->time_to_eat < 60000 || table->time_to_sleep < 60000)
		print_exit("Error timestamps");
	if (av[5])
		table->nbr_eat = new_atol(av[5]);
	else
		table->nbr_eat = -1;
}		