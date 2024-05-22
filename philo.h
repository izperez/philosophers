/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izperez <izperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 12:48:52 by izperez           #+#    #+#             */
/*   Updated: 2024/05/22 13:40:17 by izperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef PHILO_H
# define PHILO_H

#include <pthread.h>
#include "libft/libft.h"
#include <sys/time.h>

typedef struct s_philo t_philo;

typedef struct s_table
{
	int					nbr_philo;
	int					time_to_die;
	int					time_to_sleep;
	int					time_to_eat;
	int					nbr_eat;
	int					end_flag;
	int					start_flag;
	t_philo				*philos;
}					t_table;

typedef struct s_philo
{
	int				id;
	int				times_eat;
	size_t			last_meal;
	struct s_philo	*next;
	struct s_philo	*prev;
	struct s_table	*data;
	pthread_mutex_t	*fork;
	t_table			*table;
}					t_philo;

//parse.c
void	error_check(t_table *table, char **av);

//utils.c
void	print_exit(const char *msg);
t_philo	*ft_last_node(t_table *data);
void	ft_malloc(size_t item);

//init_struct.c
void	create_struct_data(t_table *data, char **av);
void	create_struct_philo(t_philo *philo);






#endif