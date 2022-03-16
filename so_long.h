/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelidris <nelidris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 10:31:58 by nelidris          #+#    #+#             */
/*   Updated: 2022/03/16 08:26:47 by nelidris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <mlx.h>
# include "libft/libft.h"

# define BUFFER_SIZE 4096
# define IN_GAME 0
# define DEFEAT 1
# define VICTORY 2

/*______________structs______________*/

typedef struct config_character
{
	int		height;
	int		width;
	void	*sprite;
	size_t	x;
	size_t	y;
}	t_character_set;

typedef struct tiles
{
	void	*grass;
	void	*rock;
	void	*collectible;
	void	*door;
	void	*playerup;
	void	*playerdown;
	void	*playerright;
	void	*playerleft;
	void	*enemyup;
	void	*enemydown;
	void	*enemyright;
	void	*enemyleft;
	void	*wall_left_up;
	void	*wall_left;
	void	*wall_mid_up;
	void	*wall_right_up;
	void	*wall_right;
	void	*wall_down_left;
	void	*wall_down;
	void	*wall_down_right;
}	t_tiles;

typedef struct config_game
{
	void			*mlx;
	void			*win;
	char			**map;
	int				count;
	int				height;
	int				width;
	int				game_status;
	t_tiles			tiles;
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
void			enemy_movement(t_game_set *game);
void			moveup_enemy(t_game_set *game, int x, int y);
void			movedown_enemy(t_game_set *game, int x, int y);
void			moveleft_enemy(t_game_set *game, int x, int y);
void			moveright_enemy(t_game_set *game, int x, int y);

/*______________display______________*/
void			display_img(t_game_set *game,
					void *img, size_t x, size_t y);
void			put_tileset(t_game_set *game, size_t y, size_t x);
void			config_tiles(t_game_set *game);
void			display_map(t_game_set *game);
int				display_rock(t_game_set *game);
void			display_character(t_game_set *game,
					t_character_set *character);

/*______________animation______________*/
int				game_animation(t_game_set *game);
void			change_animation(t_game_set *game,
					char *filenamegrass, char *filenameleg);

/*______________utils______________*/
void			put_text(t_game_set *game);
int				check_col(t_game_set *game);
size_t			ft_ptrlen(char **str);

/*______________errors______________*/
void			raise_error(char *error);

#endif