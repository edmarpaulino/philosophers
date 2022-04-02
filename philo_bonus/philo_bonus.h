/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 14:32:53 by edpaulin          #+#    #+#             */
/*   Updated: 2022/04/02 15:30:49 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# define FT_STR_MAX_INT "2147483647"

# define RED "\033[0;31m"
# define YELLOW "\033[1;33m"
# define GREEN "\033[0;32m"
# define CYAN "\033[0;36m"
# define RESET "\033[0m\n"

# include <string.h>
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

#endif
