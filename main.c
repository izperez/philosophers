/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izperez <izperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 12:48:49 by izperez           #+#    #+#             */
/*   Updated: 2024/05/28 12:15:24 by izperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_routine(t_philo *philo)
{
	t_table	*data;

	data = philo->table;
	while (1)
	{
		if (data->nbr_philo % 2 == 0)
			ft_usleep(30);
		pthread_mutex_lock(philo->fork);
		log_status(philo, "philo has taken a fork");
		pthread_mutex_lock(philo->next->fork);
		log_status(philo, "philo has taken a fork");
		log_status(philo, "philo is eating");
		philo->last_meal = get_current_time();
		ft_usleep(data->time_to_eat);
		philo->meals++;
		pthread_mutex_unlock(philo->fork);
		pthread_mutex_unlock (philo->next->fork);
		log_status(philo, "philo is sleepping");
		ft_usleep(data->time_to_sleep);
		log_status(philo, "philo is thinking");
	}
	return ;
}

void	start_simulation(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->nbr_philo)
	{
		printf("entra\n");
		pthread_create(&table->philos[i].thread, NULL, (void *)philo_routine, (void *)&table->philos[i]);
		i++;
	}
}

void	end_simulation(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->nbr_philo)
	{
		pthread_mutex_destroy(table->philos[i].fork);
		i++;
	}
	
}

int	main(int ac, char **av)
{
	t_table	table;

	if (ac == 5 || ac == 6)
		error_check(&table, av);
	else
		print_exit("Wrong input");
	init_data(&table, ac, av);
	create_struct_philo(&table);
	ft_print_struct(table.philos);
	ft_print_struct(&table);
	start_simulation(&table);
	printf("pasa\n");
	monitoring_philo(&table);
	cleanup(&table);
	return (0);
}