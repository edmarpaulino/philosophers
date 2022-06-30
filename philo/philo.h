/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 14:41:51 by edpaulin          #+#    #+#             */
/*   Updated: 2022/04/04 11:01:16 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# define FT_STR_MAX_INT "2147483647"

# define NUM_OF_PHILOS 1
# define TIME_TO_DIE 2
# define TIME_TO_EAT 3
# define TIME_TO_SLEEP 4
# define TIMES_MUST_EAT 5

# define ARG_ERROR 1
# define DATA_ERROR 2
# define PHILOS_ERROR 3
# define ALGO_ERROR 4

# define PHILO_TAKEN_A_FORK 1
# define PHILO_IS_EATING 2
# define PHILO_IS_SLEEPING 3
# define PHILO_IS_THINKING 4
# define PHILO_DIED 5

# define RED "\033[0;31m"
# define RESET_NL "\033[0m\n"

//# include <string.h>
// memset

# include <stdio.h>
// printf

# include <stdlib.h>
// malloc
// free

# include <unistd.h>
// write
// usleep

# include <sys/time.h>
// gettimeofday

# include <pthread.h>
// pthread_create
// pthread_detach
// pthread_join
// pthread_mutex_init
// pthread_mutex_destroy
// pthread_mutex_lock
// pthread_mutex_unlock

typedef pthread_mutex_t	t_mutex;

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

typedef struct s_data
{
	int			num_of_philos;
	long		time_to_die;
	long		time_to_eat;
	long		time_to_sleep;
	int			times_must_eat;
	int			is_alone;
	int			dinner_is_over;
	long		first_timestamp;
	t_mutex		lock_print;
	t_mutex		lock_dinner;
	t_mutex		*forks;
	t_list		*free_me;
}	t_data;

typedef struct s_philo
{
	int			number;
	int			total_meals;
	long		last_meal;
	pthread_t	thread;
	t_mutex		*right_fork;
	t_mutex		*left_fork;
	t_mutex		lock_last_meal;
	t_mutex		lock_total_meals;
	t_data		*data;
}	t_philo;

int		ft_isdigit(int c);
size_t	ft_strlen(char *str);
int		ft_isspace(int c);
int		ft_atoi(const char *nptr);
void	ft_putstr_fd(char *str, int fd);
void	*ft_lalloc(t_list **list, size_t alloc_size);
void	ft_lfree(t_list *list);
int		are_args_valid(const int argc, const char **argv);
int		init_data(int argc, char **argv, t_data **data);
void	destroy_data(t_data *data);
int		init_philos(t_philo **philos, t_data *data);
void	destroy_philos(t_philo *philos);
long	get_timestamp(void);
int		start_philo(t_philo *philos);
void	*waiter_algorithm(void *ptr);
void	*philo_algorithm(void *ptr);
void	print_philo_action(t_philo *philo, int action_code);
int		return_error(int error, t_data *data, t_philo *philos);

#endif
