# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/02 15:04:43 by edpaulin          #+#    #+#              #
#    Updated: 2022/04/05 13:49:29 by edpaulin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.DEFAULT_GOAL	=	all

NAME			=	philo_bonus

SRC				=	main_bonus.c \
					ft_isdigit_bonus.c \
					ft_strlen_bonus.c \
					ft_isspace_bonus.c \
					ft_atoi_bonus.c \
					ft_putstr_fd_bonus.c \
					ft_lalloc_bonus.c \
					ft_lfree_bonus.c \
					are_args_valid_bonus.c \
					return_error_bonus.c \
					get_timestamp_bonus.c \
					get_data_bonus.c \
					get_philos_bonus.c \
					destroy_data_bonus.c \
					destroy_philos_bonus.c \
					destroy_data_child_bonus.c \
					destroy_philos_child_bonus.c \
					start_alone_philo_bonus.c \
					start_philo_bonus.c \
					print_philo_action_bonus.c \
					philo_actions_bonus.c

OBJ				=	$(SRC:.c=.o)

CC				=	cc
CFLAGS			=	-Wall -Wextra -Werror -pthread -ggdb3

INC				=	-I .

%.o: %.c
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(INC) $(OBJ) -o $(NAME)

all: $(NAME)

bonus: all

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

norm:
	norminette

.PHONY: all bonus clean fclean re norm