/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izperez <izperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 12:48:49 by izperez           #+#    #+#             */
/*   Updated: 2024/05/22 13:33:36 by izperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*	1- Filo coje el tenedor derecho.
	2- Filo coje el tenedor izquiero.
	3- Filo come.
	4- Cuando termine de comer duerme.
	5- Cuando se despierte piensa hasta que pueda comer. */
void	routine(t_philo *philo)
{
	t_table	*data;

	data = philo->data;
	while (1)
	{
		//philo starts eating
		pthread_mutex_lock(philo->fork);
		ft_printf("philo has taken a fork");
		pthread_mutex_lock(philo->next->fork);
		ft_printf("philo has taken a fork");
		
		//philo is eating
		ft_printf("philo is eating");
		philo->last_meal = get_current_time();
		usleep(data->time_to_eat * 1000);
		philo->times_eat++;
		philos_finish_eating();

		//philo finish eating
		pthread_mutex_unlock(philo->fork);
		pthread_mutex_unlock (philo->next->fork);

		//philo sleeping
		usleep(data->time_to_sleep * 1000);
		
		//philo is thinking
		ft_printf("philo is thinking");
	}
	return ;
}

//1. Parse inuput (error, cheking, filling table date)
//2. Data_init (Create + init table + philos)
//3. Dinner_start
//4. Clean (no leaks) -> Philo is full/die
int	main(int ac, char **av)
{
	t_table	*table;
	// t_philo	*philo;

	table = malloc(sizeof(t_table));
	// philo = NULL;
	if (ac == 5 || ac == 6)
	{
		error_check(table, av);
	}
	else
	{
		print_message("Wrong input");
	}
	return (0);
}