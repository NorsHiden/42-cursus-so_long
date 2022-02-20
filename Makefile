# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nelidris <nelidris@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/22 10:16:37 by nelidris          #+#    #+#              #
#    Updated: 2022/02/20 07:08:51 by nelidris         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRCS =	dependencies/error_handler.c dependencies/launcher.c dependencies/valid_map.c \
		dependencies/so_long.c dependencies/animation.c dependencies/displays.c \
		dependencies/game_conf.c dependencies/player_directions.c dependencies/utils.c \
		dependencies/enemy_directions.c

OBJS = $(SRCS:.c=.o)

LIBFT = libft/libft.a

NAME = so_long

all : $(NAME)

$(NAME) : $(OBJS)
	make all bonus -C libft
	$(CC) $(CFLAGS) -l mlx -framework OpenGL -framework Appkit $(LIBFT) $(OBJS) -o $(NAME)
	
bonus: $(NAME)

clean :
	make clean -C libft
	rm -f $(OBJS)

fclean : clean
	make fclean -C libft
	rm -f $(NAME)

re : fclean all
