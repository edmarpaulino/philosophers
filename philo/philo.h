/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 14:41:51 by edpaulin          #+#    #+#             */
/*   Updated: 2022/03/31 19:19:22 by edpaulin         ###   ########.fr       */
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

# define RED "\033[0;31m"
# define YELLOW "\033[1;33m"
# define GREEN "\033[0;32m"
# define CYAN "\033[0;36m"
# define RESET "\033[0m"

# include <string.h>
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
	int		num_of_philos;
	int		time_to_die;
	int		time_to_eat;
	int		time_to_sleep;
	int		times_must_eat;
	int		is_alone;
	long	first_stamp;
	t_mutex	lock_print;
	t_mutex	lock_dinner;
	t_mutex	*forks;
	t_list	*free_me;
}	t_data;

typedef struct s_philo
{
	int			philo_number;
	int			meal_counter;
	long		last_meal;
	pthread_t	philo_thread;
	t_mutex		*right_fork;
	t_mutex		*left_fork;
	t_mutex		lock_last_meal;
	t_mutex		lock_meal_counter;
	t_data		*data;
}	t_philo;

// ==================== UTILS ====================

/**
 * @brief checks for a digit (0 through 9)
 * 
 * @param c character to check if is digit
 * @return int 1 if it is a digit or 0 if it is not
 */
int		ft_isdigit(int c);

/**
 * @brief calculate the length of a string
 * 
 * @param str string to calculate its length
 * @return size_t number of bytes in the string pointed to str
 */
size_t	ft_strlen(char *str);

/**
 * @brief checks for white-space characters
 * 
 * @param c character to check if is a white-space
 * @return int 1 if it is a white-space or 0 if it is not
 */
int		ft_isspace(int c);

/**
 * @brief convert a string to an integer
 * 
 * @param nptr string to convert to an integer
 * @return int the converted value
 */
int		ft_atoi(const char *nptr);

/**
 * @brief checks if the value is even
 * 
 * @param n value to check if is even
 * @return int 1 if it is or 0 if it is not
 */
int		ft_iseven(int n);

/**
 * @brief prints the string passed in the informed file descriptor
 * 
 * @param str pointer to string to print on file descriptor
 * @param fd file descriptor to print on
 */
void	ft_putendl(char *str, int fd);

/**
 * @brief allocate dynamic memory and add it in a list
 * 
 * @param list list to add the allocated memory
 * @param alloc_size size of memory allocation
 * @return void* pointer to the allocated memory or NULL if failed to 
 * allocate memory
 */
void	*ft_lalloc(t_list **list, size_t alloc_size);

/**
 * @brief free dynamic memory allocated inside the list
 * 
 * @param list list of allocated memory
 */
void	ft_lfree(t_list *list);

// ================== VALIDATION =================

/**
 * @brief check if arguments are valid for philosophers program, number of
 * philosopher, time to die, time to eat, time to sleep, (optional) number of
 * times each philosopher must eat
 * 
 * @param argc number of program arguments
 * @param argv program arguments array
 * @return int 1 if arguments are valid or 0 if they not
 */
int		are_args_valid(const int argc, const char **argv);

// ================ INITIALIZATION ===============

/**
 * @brief init a data structure
 * 
 * @param argc number of program arguments
 * @param argv program arguments array
 * @param data pointer to struct to init
 * @return int 0 on success or -1 on failure
 */
int		init_data(int argc, char **argv, t_data **data);

/**
 * @brief destroy data structure
 * 
 * @param data structure to destroy
 */
void	destroy_data(t_data *data);

/**
 * @brief init a philosopher array of structures
 * 
 * @param philos array of philosopher structures
 * @param data struct that contains shared values
 * @return int 0 on success or -1 on failure
 */
int		init_philos(t_philo **philos, t_data *data);

/**
 * @brief destroy philosopher array and data structure
 * 
 * @param philos philosopher array
 */
void	destroy_philos(t_philo *philos);

// ================== ALGORITHM ==================

// =================== ACTIONS ===================

// ==================== ERRORS ===================

/**
 * @brief 
 * 
 * @param error 
 * @param data 
 * @return int 
 */
int		return_error(int error, t_data *data);

// ===================== EXIT ====================

#endif
