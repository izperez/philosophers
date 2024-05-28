/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izperez <izperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 12:38:06 by izperez           #+#    #+#             */
/*   Updated: 2024/05/28 11:56:26 by izperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_data(t_table *data, char ac,char **av)
{
	data->nbr_philo = ft_atoi(av[1]);
	data->time_to_die = ft_atoi(av[2]);
	data->time_to_eat = ft_atoi(av[3]);
	data->time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
		data->nbr_eat = ft_atoi(av[5]);
	else
		data->nbr_eat = -1;
	data->end_flag = 0;
	data->start_flag = 0;
	pthread_mutex_init(&data->mutex, NULL);
}

void	create_struct_philo(t_table *table)
{
	int		i;
	t_philo	*philo;

	i = 0;
	table->philos = malloc(sizeof(t_philo) * table->nbr_philo);
	usleep(5);
	if (table->philos == NULL)
		return ;
	philo = &table->philos[i];
	while (i < table->nbr_philo)
	{
		philo->id = i + 1;
		philo->meals = 0;
		philo->last_meal = 0;
		philo->table = table;
		philo->fork = malloc(sizeof(pthread_mutex_t));
		if (philo->fork == NULL)
			return ;
		pthread_mutex_init(philo->fork, NULL);
		if (i < table->nbr_philo)
		{
			philo->prev = &table->philos[i - 1];
			table->philos[i - 1].next = philo;
			i++;
		}
	}
	table->philos[0].prev = &table->philos[table->nbr_philo - 1];
	table->philos[table->nbr_eat-1].next = &table->philos[0];
}

void	monitoring_philo(t_table *table)
{
	int	i;

	i = 0;
	while (!table->end_flag)
	{
		while (i < table->nbr_philo)
		{
			if (get_current_time() - table->philos[i].last_meal > (size_t)table->time_to_die)
			{
				log_status(&table->philos[i], "philo has died");
				table->end_flag = 1;
				return ;
			}
			i++;
		}
		usleep(1000);
	}
}
