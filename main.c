/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izperez <izperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 12:48:49 by izperez           #+#    #+#             */
/*   Updated: 2024/06/03 12:36:43 by izperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void *philo_routine(void *arg)
{
	t_philo *philo;
	//(void)arg;
	philo = (t_philo *)arg;

	printf("el fide es el : %i\n", philo->id);
	while (1)
	{
		printf("tamo en el while\n");
		if (philo->table->nbr_philo % 2 == 0)
			usleep(10);
		printf("seguimo en el while\n");
		printf("right fork: %p\n", philo->table->fork[philo->rigth_fork]);
		pthread_mutex_lock(&philo->table->fork[philo->rigth_fork]);
		log_status(philo, "philo has taken a fork");
		pthread_mutex_lock(&philo->table->fork[philo->left_fork]);
		log_status(philo, "philo has taken a fork");
		log_status(philo, "philo is eating");
		philo->last_meal = get_current_time();
		ft_usleep(philo->table->time_to_eat);
		philo->meals++;
		pthread_mutex_unlock(&philo->table->fork[philo->rigth_fork]);
		pthread_mutex_unlock(&philo->table->fork[philo->left_fork]);
		log_status(philo, "philo is sleepping");
		ft_usleep(philo->table->time_to_sleep);
		log_status(philo, "philo is thinking");
	}
	return (NULL);
}

void start_simulation(t_philo *philo)
{
	int i;

	i = 0;
	
	//getchar();
	while (i < philo->table->nbr_philo)
	{
		printf("start simulation %i\n", i);
		if (pthread_create(philo[i].table->thread, NULL, &philo_routine, &philo[i]) != 0)
			print_exit("ERROR\n");
		i++;
	}
}

void end_simulation(t_table *table)
{
	int i;

	i = 0;
	while (i < table->nbr_philo)
	{
		pthread_mutex_destroy(table->fork);
		i++;
	}
}

int main(int ac, char **av)
{
	t_table table;
	t_philo *philo;

	philo = NULL;

	if (ac == 5 || ac == 6)
		error_check(&table, av);
	else
		print_exit("Wrong input");
	
	init_data(&table, ac, av);
	philo = create_struct_philo(philo, &table);

	//getchar();
	start_simulation(philo);
	cleanup2(philo);
	return (0);
}