/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izperez <izperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 12:38:06 by izperez           #+#    #+#             */
/*   Updated: 2024/06/03 12:49:51 by izperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_data(t_table *data, char ac,char **av)
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
	while(i < data->nbr_philo)
		if(pthread_mutex_init(&data->fork[i++], NULL) == -1)
			print_exit("Error\n");
}

t_philo	*create_struct_philo(t_philo *philo, t_table *table)
{
	int		i;

	i = 0;
	philo = malloc(sizeof(t_philo)* table->nbr_philo);
	
	table->thread = malloc(sizeof(pthread_t) * table->nbr_philo);
	if (philo == NULL)
		return (philo);
	while (i < table->nbr_philo)
	{
		philo[i].id = i + 1;
		//printf("el philo [%i] con id [%i]\n",i,philo[i].id);
		philo[i].meals = 0;
		philo[i].last_meal = get_current_time();
		philo[i].table = table;
		philo[i].rigth_fork = i;
		philo[i].left_fork = (i + 1) % table->nbr_philo;
		i++;
	}
	return (philo);
}

void	monitoring_philo(t_philo *philo, t_table *table)
{
	int	i;

	i = 0;
	while (!table->end_flag)
	{
		while (i < table->nbr_philo)
		{
			if (get_current_time() - philo[i].last_meal > (size_t)table->time_to_die)
			{
				log_status(philo, "philo has died");
				table->end_flag = 1;
				return ;
			}
			i++;
		}
		usleep(1000);
	}
}
