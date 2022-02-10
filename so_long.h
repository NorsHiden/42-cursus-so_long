/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelidris <nelidris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 10:31:58 by nelidris          #+#    #+#             */
/*   Updated: 2022/02/08 21:52:12 by nelidris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <fcntl.h>
# include <mlx.h>
# include "ft_printf/ft_printf.h"

# define BUFFER_SIZE 4096

/*______________structs______________*/

typedef struct config_character
{
	int		height;
	int		width;
	void	*sprite;
	size_t	x;
	size_t	y;
}	t_character_set;

typedef struct config_game
{
	void			*mlx;
	void			*win;
	char			**map;
	int				count;
	int				height;
	int				width;
	t_character_set	*character;
}	t_game_set;

/*______________main_fun______________*/
void			launch_game(char **map);
t_character_set	*set_up_character(char **map);
t_game_set		*set_up_game(char **map, t_character_set *character);

/*______________valid_map______________*/
int				valid_map(char *path);
int				valid_characters(char *map);
int				valid_map_size(char **map);
int				valid_map_conf(char *map);

/*______________directions______________*/
void			moveup_player(t_game_set *game);
void			movedown_player(t_game_set *game);
void			moveleft_player(t_game_set *game);
void			moveright_player(t_game_set *game);

/*______________display______________*/
void			display_img(t_game_set *game,
					char *filename, size_t x, size_t y);
void			put_tileset(t_game_set *game, size_t y, size_t x);
void			display_map(t_game_set *game);
void			display_character(t_game_set *game,
					t_character_set *character);

/*______________animation______________*/
int				col_an(t_game_set *game);
void			change_an(t_game_set *game,
					char *filenamegrass, char *filenameleg);

/*______________utils______________*/
void			put_text(t_game_set *game);
int				check_col(t_game_set *game);
size_t			ft_ptrlen(char **str);

/*______________errors______________*/
void			raise_error(char *error);

#endif