/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izperez <izperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 12:48:49 by izperez           #+#    #+#             */
/*   Updated: 2024/06/03 13:53:09 by izperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void *philo_routine(void *arg)
{
	t_philo *philo;
	philo = (t_philo *)arg;

	while (1)
	{
		if (philo->id % 2 == 0)
			ft_usleep(100);
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
		if (philo->meals == philo->table->nbr_eat)
		{
			philo->full = 1;
			philo->table->end_flag = 1;
		}
		else if (get_current_time() - philo->last_meal > philo->table->time_to_die)
		{
			log_status(philo, "philo has died");
			philo->table->end_flag = 1;
			philo->dead = 1;
		}
	}
	return (NULL);
}

void start_simulation(t_philo *philo)
{
	int 		i;
	pthread_t	monitor;

	i = 0;
	while (i < philo->table->nbr_philo)
	{
		if (pthread_create(philo[i].table->thread, NULL, &philo_routine, &philo[i]) != 0)
			print_exit("ERROR");
		i++;
		if (pthread_create(&monitor, NULL, monitoring_philo, philo) != 0)
			print_exit("ERROR");
		pthread_join(monitor, NULL);
		if (philo->dead == 1)
			print_exit("philo has died");
		else if (philo->full == 1)
			print_exit("philo is full");
	}
}

void end_simulation(t_table *table)
{
	int i;

	i = 0;
	while (i < table->nbr_philo)
	{
		pthread_mutex_destroy(&table->fork[i]);
		i++;
	}
	free(table->fork);
	free(table->thread);
}

int main(int ac, char **av)
{
	t_table table;
	t_philo *philos;

	philos = NULL;

	if (ac == 5 || ac == 6)
		error_check(&table, av);
	else
		print_exit("Wrong input");
	init_data(&table, ac, av);
	philos = create_struct_philo(philos, &table);
	start_simulation(philos);
	end_simulation(&table);
	free (philos);
	return (0);
}