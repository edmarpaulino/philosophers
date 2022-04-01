# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/23 14:36:00 by edpaulin          #+#    #+#              #
#    Updated: 2022/04/01 09:36:37 by edpaulin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.DEFAULT_GOAL	=	all

NAME			=	philo

SRC				=	main.c \
					ft_isdigit.c \
					ft_strlen.c \
					ft_isspace.c \
					ft_atoi.c \
					ft_iseven.c \
					ft_putendl.c \
					ft_lalloc.c \
					ft_lfree.c \
					init_data.c \
					destroy_data.c \
					init_philos.c \
					destroy_philos.c \
					are_args_valid.c \
					return_error.c \
					start_philo.c

OBJ = $(SRC:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror -ggdb3 -pthread

INC = -I .


%.o: %.c
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(INC) $(OBJ) -o $(NAME)

all: $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

############ REMOVE ##############
run: $(NAME)
	./$(NAME) 5 1000 200 300 10

test: $(NAME)
	./test.sh

norm:
	norminette
##################################

.PHONY: all clean fclean re run norm
