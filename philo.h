/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izperez <izperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 12:48:52 by izperez           #+#    #+#             */
/*   Updated: 2024/06/03 13:47:37 by izperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include "libft/libft.h"
# include <pthread.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_philo	t_philo;

typedef struct s_table
{
	int					nbr_philo;
	int					time_to_die;
	int					time_to_sleep;
	int					time_to_eat;
	int					nbr_eat;
	long				end_flag;
	long				start_flag;
	pthread_mutex_t		mutex;
	pthread_mutex_t		*fork;
	pthread_t			*thread;
}						t_table;

typedef struct s_philo
{
	int					id;
	int					meals;
	size_t				last_meal;
	int					rigth_fork;
	int					left_fork;
	struct s_table		*table;
}						t_philo;

// main.c
void					*philo_routine(void *arg);
void					start_simulation(t_philo *philo);
void					end_simulation(t_table *table);

// parse.c
void					error_check(t_table *table, char **av);
void					cleanup(t_table *table);
void					ft_free_philo(t_table *table);
void					cleanup2(t_philo *philo);

// utils.c
void					print_exit(const char *msg);
long int				get_current_time(void);
void					log_status(t_philo *philo, char *status);
void					ft_usleep(__useconds_t milisec);

// init_struct.c
void					init_data(t_table *data, char ac, char **av);
t_philo					*create_struct_philo(t_philo *philo, t_table *table);
void					monitoring_philo(t_philo *philo, t_table *table);

#endif