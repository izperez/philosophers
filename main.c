/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izperez <izperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 12:48:49 by izperez           #+#    #+#             */
/*   Updated: 2024/05/27 12:17:15 by izperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*	1- Filo coje el tenedor derecho.
	2- Filo coje el tenedor izquiero.
	3- Filo come.
	4- Cuando termine de comer duerme.
	5- Cuando se despierte piensa hasta que pueda comer. */
void	philo_routine(t_philo *philo)
{
	t_table	*data;

	data = philo->table;
	while (1)
	{
		//philo starts eating
		pthread_mutex_lock(philo->fork);
		log_status(philo, "philo has taken a fork");
		pthread_mutex_lock(philo->next->fork);
		log_status(philo, "philo has taken a fork");
		
		//philo is eating
		log_status(philo, "philo is eating");
		philo->last_meal = get_current_time();
		usleep(data->time_to_eat * 1000);
		philo->meals++;

		//philo finish eating
		pthread_mutex_unlock(philo->fork);
		pthread_mutex_unlock (philo->next->fork);

		//philo sleeping
		log_status(philo, "philo is sleepping");
		usleep(data->time_to_sleep * 1000);
		
		//philo is thinking
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

//1. Parse inuput (error, cheking, filling table date)
//2. Data_init (Create + init table + philos)
//3. Dinner_start
//4. Clean (no leaks) -> Philo is full/die
int	main(int ac, char **av)
{
	t_table	table;

	if (ac == 5 || ac == 6)
		error_check(&table, av);
	else
		print_exit("Wrong input");
	init_data(&table, ac, av);
	create_struct_philo(&table);
	start_simulation(&table);
	printf("llega\n");
	monitoring_philo(&table);
	cleanup(&table);
	return (0);
}