/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 14:32:53 by edpaulin          #+#    #+#             */
/*   Updated: 2022/04/04 11:01:32 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# define FT_STR_MAX_INT "2147483647"

# define NUM_OF_PHILOS 1
# define TIME_TO_DIE 2
# define TIME_TO_EAT 3
# define TIME_TO_SLEEP 4
# define TIMES_MUST_EAT 5

# define SEM_FORKS_NAME "/sem_forks"
# define SEM_LOCK_PRINT_NAME "/sem_lock_print"
# define SEM_DINNER_IS_OVER_NAME "/sem_dinner_is_over"
# define SEM_I_DIED_NAME "/sem_i_died"

# define ARG_ERROR 1
# define DATA_ERROR 2
# define PHILOS_ERROR 3
# define ALGO_ERROR 4

# define PHILO_TAKEN_A_FORK 1
# define PHILO_IS_EATING 2
# define PHILO_IS_SLEEPING 3
# define PHILO_IS_THINKING 4
# define PHILO_DIED 5

# define NOT_DESTROY_SEM 0
# define DESTROY_SEM 1

# define RED "\033[0;31m"
# define RESET_NL "\033[0m\n"

// # include <string.h>
// memset

# include <stdio.h>
// printf

# include <stdlib.h>
// malloc
// free
// exit

# include <unistd.h>
// write
// fork
// usleep

# include <pthread.h>
// pthread_create
// pthread_detach
// pthread_join

# include <signal.h>
// kill

# include <sys/types.h>
// fork
// kill
// waitpid

# include <sys/time.h>
// gettimeofday

# include <sys/wait.h>
// waitpid

# include <fcntl.h>
# include <sys/stat.h>
// sem_open

# include <semaphore.h>
// sem_open
// sem_close
// sem_post
// sem_wait
// sem_unlink

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
	long		first_timestamp;
	int			*pid_arr;
	sem_t		*forks;
	sem_t		*lock_print;
	sem_t		*dinner_is_over;
	sem_t		*i_died;
	t_list		*free_me;
}	t_data;

typedef struct s_philo
{
	int			number;
	int			total_meals;
	long		last_meal;
	t_data		*data;
}	t_philo;

int		ft_isdigit(int c);
size_t	ft_strlen(char *str);
int		ft_isspace(int c);
int		ft_atoi(const char *nptr);
void	ft_putstr_fd(char *str, int fd);
void	*ft_lalloc(t_list **list, size_t alloc_size);
void	ft_lfree(t_list *list);
long	get_timestamp(void);
int		are_args_valid(const int argc, const char **argv);
int		init_data(int argc, char **argv, t_data **data);
int		init_philos(t_philo **philos, t_data *data);
void	destroy_data(t_data *data, int sem);
int		start_philo(t_philo *philos);
void	print_philo_action(t_philo *philo, int action_code);
void	philo_algorithm(t_philo *philo);
int		return_error(int error, t_data *data);

#endif
