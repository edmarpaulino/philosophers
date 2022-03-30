/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 14:41:51 by edpaulin          #+#    #+#             */
/*   Updated: 2022/03/30 15:38:26 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# define FT_S_MAX_INT "2147483647"

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

// UTILS
int				ft_isdigit(int c);
size_t			ft_strlen(char *str);
int				ft_isspace(int c);

// VALIDATION
int				are_inputs_valid(const char **inputs);

#endif
