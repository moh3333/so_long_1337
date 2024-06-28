# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mthamir <mthamir@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/18 22:20:40 by mthamir           #+#    #+#              #
#    Updated: 2024/06/18 22:20:47 by mthamir          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME := so_long

CC := cc

FLAGS := -Wall -Wextra -Werror

MLX_FLAGS := -lmlx -framework OpenGL -framework AppKit

SRC := so_long_main.c so_long_0.c so_long_1.c g_n_l.c g_n_l_u.c ft_printf.c parsing_0.c parsing_1.c parsing_2.c

OBJ := $(SRC:.c=.o)

HEADER := so_long.h

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(FLAGS) $(MLX_FLAGS) $(OBJ)  -o $(NAME)

%.o : %.c $(HEADER)
	$(CC) $(FLAGS) -c $< -o $@

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all