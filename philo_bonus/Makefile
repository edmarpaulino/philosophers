# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/02 15:04:43 by edpaulin          #+#    #+#              #
#    Updated: 2022/04/02 15:30:30 by edpaulin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.DEFAULT_GOAL	=	all

NAME			=	philo_bonus

SRC				=	main.c \
					ft_isdigit.c \
					ft_strlen.c \
					ft_isspace.c \
					ft_atoi.c \
					ft_iseven.c \
					ft_putendl.c \
					ft_lalloc.c \
					ft_lfree.c \
					are_args_valid.c

OBJ				=	$(SRC:.c=.o)

CC				=	cc
CFLAGS			=	-Wall -Wextra -Werror -pthread -ggdb3

INC				=	-I .

%.o: %.c
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(INC) $(OBJ) -o $(NAME)

all: $(NAME)

clean:
	@rm $(OBJ)

fclean: clean
	@rm $(NAME)

re: fclean all

norm:
	norminette

.PHONY: all clean fclean re norm