# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: user42 <user42@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/23 14:36:00 by edpaulin          #+#    #+#              #
#    Updated: 2022/05/11 21:24:18 by user42           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.DEFAULT_GOAL	=	all

NAME			=	philo

SRC				=	main.c \
					ft_isdigit.c \
					ft_strlen.c \
					ft_isspace.c \
					ft_atoi.c \
					ft_putstr_fd.c \
					ft_lalloc.c \
					ft_lfree.c \
					init_data.c \
					destroy_data.c \
					init_philos.c \
					destroy_philos.c \
					are_args_valid.c \
					return_error.c \
					start_philo.c \
					get_timestamp.c \
					print_philo_action.c \
					waiter_algorithm.c \
					philo_algorithm.c

OBJ = $(SRC:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror -pthread

INC = -I .

%.o: %.c
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(INC) $(OBJ) -o $(NAME)

all: $(NAME)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

norm:
	norminette

.PHONY: all clean fclean re norm
