/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izperez <izperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 12:38:06 by izperez           #+#    #+#             */
/*   Updated: 2024/06/17 12:29:03 by izperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_data(t_table *data, char ac, char **av)
{
	int	i;

	i = 0;
	data->nbr_philo = ft_atoi(av[1]);
	data->time_to_die = ft_atoi(av[2]);
	data->time_to_eat = ft_atoi(av[3]);
	data->time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
		data->nbr_eat = ft_atoi(av[5]);
	else
		data->nbr_eat = -1;
	data->end_flag = 0;
	data->start_flag = get_current_time();
	data->fork = malloc(sizeof(pthread_mutex_t) * data->nbr_philo);
	if (data->fork == NULL)
		return ;
	while (i < data->nbr_philo)
		if (pthread_mutex_init(&data->fork[i++], NULL) == -1)
			print_exit("Error\n");
	data->thread = malloc(sizeof(pthread_t) * data->nbr_philo);
	if (data->thread == NULL)
		return ;
	pthread_mutex_init(&data->mutex, NULL);
}

t_philo	*create_struct_philo(t_philo *philo, t_table *table)
{
	int		i;

	i = 0;
	philo = malloc(sizeof(t_philo) * table->nbr_philo);
	if (philo == NULL)
		return (philo);
	while (i < table->nbr_philo)
	{
		philo[i].id = i + 1;
		philo[i].meals = 0;
		philo[i].last_meal = get_current_time();
		philo[i].table = table;
		philo[i].right_fork = i;
		philo[i].left_fork = (i + 1) % table->nbr_philo;
		philo[i].dead = 0;
		philo[i].full = 0;
		i++;
	}
	return (philo);
}

void	*monitoring_philo(void *args)
{
	int				i;
	t_philo			*philo;

	i = 0;
	philo = (t_philo *)args;
	while (!philo->table->end_flag)
	{
		i = 0;
		while (i < philo->table->nbr_philo)
		{
			if (get_current_time() - philo[i].last_meal
				> philo->table->time_to_die && !philo->table->end_flag)
			{
				log_status(&philo[i], "philo has died");
				philo->table->end_flag = 1;
				return (NULL);
			}
			i++;
		}
	}
	return (NULL);
}
