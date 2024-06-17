/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izperez <izperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 12:48:49 by izperez           #+#    #+#             */
/*   Updated: 2024/06/17 12:34:40 by izperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	philo_routine_aux(t_philo *philo)
{
	if (philo->id % 2 == 0)
		ft_usleep(10);
	pthread_mutex_lock(&philo->table->fork[philo->right_fork]);
	log_status(philo, "has taken a fork");
	pthread_mutex_lock(&philo->table->fork[philo->left_fork]);
	log_status(philo, "has taken a fork");
	log_status(philo, "is eating");
}

void	*philo_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (philo->table->end_flag == 0)
	{
		philo_routine_aux(philo);
		philo->last_meal = get_current_time();
		ft_usleep(philo->table->time_to_eat);
		philo->meals++;
		pthread_mutex_unlock(&philo->table->fork[philo->right_fork]);
		pthread_mutex_unlock(&philo->table->fork[philo->left_fork]);
		log_status(philo, "is sleeping");
		ft_usleep(philo->table->time_to_sleep);
		log_status(philo, "is thinking");
		if (philo->meals == philo->table->nbr_eat)
		{
			philo->full = 1;
			break ;
		}
	}
	return (NULL);
}

void	start_simulation(t_philo *philo)
{
	int			i;
	pthread_t	monitor;

	i = 0;
	while (i < philo->table->nbr_philo)
	{
		if (pthread_create(&philo[i].table->thread[i], NULL,
				&philo_routine, &philo[i]) != 0)
			print_exit("ERROR");
		i++;
	}
	if (pthread_create(&monitor, NULL, monitoring_philo, philo) != 0)
		print_exit("ERROR");
	pthread_join(monitor, NULL);
	i = 0;
	while (i < philo->table->nbr_philo)
	{
		if (pthread_join(philo->table->thread[i], NULL) != 0)
			print_exit("ERROR");
		i++;
	}
	if (philo->full == 1)
		printf("%d is full\n", philo->id);
}

void	end_simulation(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->nbr_philo)
	{
		pthread_mutex_destroy(&table->fork[i]);
		i++;
	}
	free(table->fork);
	free(table->thread);
}

int	main(int ac, char **av)
{
	t_table	table;
	t_philo	*philos;

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
