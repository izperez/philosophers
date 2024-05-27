/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izperez <izperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 12:48:52 by izperez           #+#    #+#             */
/*   Updated: 2024/05/23 13:40:43 by izperez          ###   ########.fr       */
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
	pthread_mutex_t		mutex;
	struct s_philo		*philos;
}					t_table;

typedef struct s_philo
{
	int				id;
	int				meals;
	size_t			last_meal;
	struct s_philo	*next;
	struct s_philo	*prev;
	struct s_table	*data;
	pthread_mutex_t	*fork;
	struct s_table	*table;
	pthread_t		thread;
}					t_philo;

//main.c
void	philo_routine(t_philo *philo);
void	start_simulation(t_table *table);
void	end_simulation(t_table *table);

//parse.c
void	error_check(t_table *table, char **av);
void	cleanup(t_table *table);

//utils.c
void	print_exit(const char *msg);
size_t	get_current_time(void);
void	log_status(t_philo *philo, char *status);

//init_struct.c
void	init_data(t_table *data, char ac, char **av);
void	create_struct_philo(t_table *table);
void	monitoring_philo(t_table *table);



#endif