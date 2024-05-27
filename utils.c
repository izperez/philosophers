/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izperez <izperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 13:47:25 by izperez           #+#    #+#             */
/*   Updated: 2024/05/23 13:01:35 by izperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//printf message + exit
void	print_exit(const char *msg)
{
	ft_printf("%s\n", msg);
	exit(EXIT_FAILURE);
}

//finds the last node of the list
// t_philo	*ft_last_node(t_philo *philo)
// {
// 	while (philo->next != NULL)
// 	{
// 		philo = philo->next;
// 	}
// 	return (philo);
// }

/* Gets the time of time_to_eat/sleep/think */
size_t	get_current_time(void)
{
	struct timeval	start_time;
	int				is_initialized;
	struct timeval	current_time;
	size_t			time_pased;

	is_initialized = 0;
	gettimeofday(&current_time, NULL);
	if (!is_initialized)
	{
		start_time = current_time;
		is_initialized = 1;
	}
	time_pased = (current_time.tv_sec - start_time.tv_sec) * 1000;
	time_pased += (current_time.tv_usec - start_time.tv_usec) / 1000;
	return (time_pased);
}

/* print the philo message when is eating, sleeping, thinking
 * According to the time. Because of mutex
*/
void	log_status(t_philo *philo, char *status)
{
	long	time_date_i;
	
	time_date_i = get_current_time() - philo->data->start_flag;
	pthread_mutex_lock(&philo->table->mutex);
	ft_printf("%zu %d %s\n", time_date_i, philo->id, status);
	pthread_mutex_unlock(&philo->table->mutex);
}



