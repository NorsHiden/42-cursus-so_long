# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nelidris <nelidris@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/22 10:16:37 by nelidris          #+#    #+#              #
#    Updated: 2022/02/23 10:18:21 by nelidris         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRCS =	dependencies/error_handler.c dependencies/launcher.c dependencies/valid_map.c \
		dependencies/so_long.c dependencies/animation.c dependencies/displays.c \
		dependencies/game_conf.c dependencies/player_directions.c dependencies/utils.c \
		dependencies/enemy_directions.c

LIBFT = libft/libft.a

NAME = so_long

BLUE = "\033[0;34m"
GREEN = "\033[1;32m"
YELLOW = "\033[0;33m"
LIGHT_YELLOW = "\033[1;33m"
NOCOLOR = "\033[0;37m"

all : $(NAME)

$(NAME) :
	@echo $(BLUE)"Compiling so_long..."$(NOCOLOR)
	@echo $(GREEN)" .▄▄ ·        ▄▄▌         ▐ ▄  ▄▄ •  "$(NOCOLOR)
	@echo $(GREEN)" ▐█ ▀. ▪      ██•  ▪     •█▌▐█▐█ ▀ ▪ "$(NOCOLOR)
	@echo $(GREEN)" ▄▀▀▀█▄ ▄█▀▄  ██▪   ▄█▀▄ ▐█▐▐▌▄█ ▀█▄ "$(NOCOLOR)
	@echo $(GREEN)" ▐█▄▪▐█▐█▌.▐▌ ▐█▌▐▌▐█▌.▐▌██▐█▌▐█▄▪▐█ "$(NOCOLOR)
	@echo $(GREEN)"  ▀▀▀▀  ▀█▄▀▪ .▀▀▀  ▀█▄▀▪▀▀ █▪·▀▀▀▀  "$(NOCOLOR)
	@make all -C libft > /dev/null
	@$(CC) $(CFLAGS) -l mlx -framework OpenGL -framework Appkit $(LIBFT) $(SRCS) -o $(NAME)
	@echo $(GREEN)"Compilation finished !!"$(NOCOLOR)
	@echo $(YELLOW)"type "$(LIGHT_YELLOW)"\`./so_long maps/{choose_a_map}\`"$(YELLOW)" to start the game!"$(NOCOLOR)
	
bonus: $(NAME)

clean :
	@echo $(GREEN)"Repository has been cleaned."$(NOCOLOR)
	@make clean -C libft > /dev/null

fclean : clean
	@make fclean -C libft > /dev/null
	@rm -f $(NAME)

re : fclean all
