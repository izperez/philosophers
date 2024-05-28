/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izperez <izperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 11:43:26 by izperez           #+#    #+#             */
/*   Updated: 2024/05/28 11:36:56 by izperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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

void	error_check(t_table *table, char **av)
{
	table->nbr_philo = new_atol(av[1]);
	table->time_to_die = new_atol(av[2]) * 1000;
	table->time_to_eat = new_atol(av[3]) * 1000;
	table->time_to_sleep = new_atol(av[4]) * 1000;
	if (table->time_to_die < 60000 || table->time_to_eat < 60000 || table->time_to_sleep < 60000)
		print_exit("Error times");
	if (av[5])
		table->nbr_eat = new_atol(av[5]);
	else
		table->nbr_eat = -1;
}

void	cleanup(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->nbr_philo)
	{
		pthread_join(table->philos[i].thread, NULL);
		pthread_mutex_destroy(table->philos[i].fork);
		free(table->philos[i].fork);
	}
	pthread_mutex_destroy(&table->mutex);
	free(table->philos);
}

void	ft_free_philo(t_table *table)
{
	if (table->philos)
	{
		free (table->philos);
		table->philos = NULL;
	}
}