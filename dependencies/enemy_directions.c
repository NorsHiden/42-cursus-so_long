/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_directions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelidris <nelidris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 09:52:26 by nelidris          #+#    #+#             */
/*   Updated: 2022/02/19 10:11:18 by nelidris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	moveup_enemy(t_game_set *game, int x, int y)
{
	game->map[y][x] = '0';
	game->map[y - 1][x] = 'Q';
	display_img(game, "tilesets_xpm/grass_2.xpm", x, y);
	display_img(game, "tilesets_xpm/enup.xpm", x, y - 1);
	if (game->map[y - 2][x] == 'P')
		game->game_status = DEFEAT;
}

void	movedown_enemy(t_game_set *game, int x, int y)
{
	game->map[y][x] = '0';
	game->map[y + 1][x] = 'Q';
	display_img(game, "tilesets_xpm/grass_2.xpm", x, y);
	display_img(game, "tilesets_xpm/endown.xpm", x, y + 1);
	if (game->map[y + 2][x] == 'P')
		game->game_status = DEFEAT;
}

void	moveleft_enemy(t_game_set *game, int x, int y)
{
	game->map[y][x] = '0';
	game->map[y][x - 1] = 'Q';
	display_img(game, "tilesets_xpm/grass_2.xpm", x, y);
	display_img(game, "tilesets_xpm/enleft.xpm", x - 1, y);
	if (game->map[y][x - 2] == 'P')
		game->game_status = DEFEAT;
}

void	moveright_enemy(t_game_set *game, int x, int y)
{
	game->map[y][x] = '0';
	game->map[y][x + 1] = 'Q';
	display_img(game, "tilesets_xpm/grass_2.xpm", x, y);
	display_img(game, "tilesets_xpm/enright.xpm", x + 1, y);
	if (game->map[y][x + 2] == 'P')
		game->game_status = DEFEAT;
}

void	enemy_movement(t_game_set *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == 'G')
			{
				if (game->map[y - 1][x] == '0')
					moveup_enemy(game, x, y);
				else if (game->map[y + 1][x] == '0')
					movedown_enemy(game, x, y);
				else if (game->map[y][x - 1] == '0')
					moveleft_enemy(game, x, y);
				else if (game->map[y][x + 1] == '0')
					moveright_enemy(game, x, y);
				display_img(game, "tilesets_xpm/grass_2.xpm", x, y);
			}
			x++;
		}
		y++;
	}
}
