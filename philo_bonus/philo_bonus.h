/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 14:32:53 by edpaulin          #+#    #+#             */
/*   Updated: 2022/04/04 21:34:55 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# define FT_STR_MAX_INT "2147483647"

# define PHILO_TAKEN_A_FORK 1
# define PHILO_IS_EATING 2
# define PHILO_IS_SLEEPING 3
# define PHILO_IS_THINKING 4
# define PHILO_DIED 5

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
	int			time_to_die;
	int			time_to_eat;
	int			time_to_sleep;
	int			times_must_eat;
	long		first_timestamp;
	int			*pid_array;
	sem_t		*forks;
	sem_t		*lock_print;
	sem_t		*death;
	sem_t		*dinner_is_over;
}	t_data;

typedef struct s_philo
{
	int			num;
	int			num_of_meals;
	long		last_meal_timestamp;
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
t_data	*get_data(const int argc, const char **argv);
t_philo	*get_philos(t_data *data);
void	destroy_data(t_data *data);
void	destroy_philos(t_philo *philos);
void	destroy_data_child(t_data *data);
void	destroy_philos_child(t_philo *philos);
int		start_alone_philo(t_philo *philos);
int		start_philo_bonus(t_philo *philos);
void	philo_actions(t_philo *philo);
void	print_philo_action(t_philo *philo, int action_code);

#endif
