/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izperez <izperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 13:47:25 by izperez           #+#    #+#             */
/*   Updated: 2024/05/22 13:49:27 by izperez          ###   ########.fr       */
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
t_philo	*ft_last_node(t_philo *philo)
{
	while (philo->next != NULL)
	{
		philo = philo->next;
	}
	return (philo);
}

/* Gets the time of time_to_eat/sleep/think */
void	get_current_time(t_philo philo)
{
	
}

/* print the philo message when is eating, sleeping, thinking
 * According to the time. Because of mutex
*/



