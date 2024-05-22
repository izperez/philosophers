/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izperez <izperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 12:38:06 by izperez           #+#    #+#             */
/*   Updated: 2024/05/22 13:32:13 by izperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//creates the struct data
void	create_struct_data(t_table *data, char **av)
{
	data = malloc(sizeof(t_table));
	if (data != NULL)
	{
		data->nbr_philo = ft_atoi(av[1]);
		data->time_to_die = ft_atoi(av[2]);
		data->time_to_eat = ft_atoi(av[3]);
		data->time_to_sleep = ft_atoi(av[4]);
		data->nbr_eat = ft_atoi(av[5]);
		data->end_flag = 0;
		data->start_flag = 0;
	}
	return (NULL);
}

//create the struct of the philo
void	create_struct_philo(t_philo *philo)
{
	t_philo	*new_philo;
	t_philo	*last_philo;
	
	philo = malloc(sizeof(t_philo));
	if (philo == NULL)
		return (NULL);
	if (philo == NULL)
	{
		new_philo = philo;
		philo->next = NULL;
		philo->prev == NULL;
	}
	else
	{
		last_philo = ft_last_node(philo);
	}
	philo->id = 0;
	philo->times_eat = 0;
	philo->last_meal = 0;
	philo->fork == NULL;
}

// void	init_struct_data();

// void	init_struct_philo();