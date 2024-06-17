/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izperez <izperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 13:47:25 by izperez           #+#    #+#             */
/*   Updated: 2024/06/17 12:34:15 by izperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_exit(const char *msg)
{
	ft_printf("%s\n", msg);
	exit(EXIT_FAILURE);
}

long int	get_current_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

void	log_status(t_philo *philo, char *status)
{
	long	time_date_i;

	time_date_i = get_current_time() - philo->table->start_flag;
	pthread_mutex_lock(&philo->table->mutex);
	if (philo->table->end_flag == 0)
		printf("%ld %d %s\n", time_date_i, philo->id, status);
	pthread_mutex_unlock(&philo->table->mutex);
}

void	ft_usleep(long milisec)
{
	long	start;

	start = get_current_time();
	while (1)
	{
		if (get_current_time() - milisec >= start)
			break ;
		usleep(50);
	}
}
