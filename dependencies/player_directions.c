/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_directions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelidris <nelidris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 20:27:38 by nelidris          #+#    #+#             */
/*   Updated: 2022/02/08 21:15:44 by nelidris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	moveup_player(t_game_set *game)
{
	size_t	x;
	size_t	y;

	x = game->character->x;
	y = game->character->y;
	display_img(game, "tilesets_xpm/grass_2.xpm", x, y);
	if ((game->map[y - 1][x] == 'E' && check_col(game))
		|| (game->map[y - 1][x] == 'H'))
		exit(0);
	else if (y > 1 && game->map[y - 1][x] != '1' && game->map[y - 1][x] != 'E')
	{
		display_img(game, "tilesets_xpm/grass_2.xpm", x, (y - 1));
		display_img(game, "tilesets_xpm/up2.xpm", x, (y - 1));
		if (game->map[y - 1][x] == 'C')
			game->map[y - 1][x] = '0';
		game->character->y--;
		put_text(game);
	}
	else
		display_img(game, "tilesets_xpm/up2.xpm", x, y);
}

void	moveleft_player(t_game_set *game)
{
	size_t	x;
	size_t	y;

	x = game->character->x;
	y = game->character->y;
	display_img(game, "tilesets_xpm/grass_2.xpm", x, y);
	if ((game->map[y][x - 1] == 'E' && check_col(game))
		|| (game->map[y][x - 1] == 'H'))
		exit(0);
	else if (x > 1 && game->map[y][x - 1] != '1' && game->map[y][x - 1] != 'E')
	{
		display_img(game, "tilesets_xpm/grass_2.xpm", (x - 1), y);
		display_img(game, "tilesets_xpm/left2.xpm", (x - 1), y);
		if (game->map[y][x - 1] == 'C')
			game->map[y][x - 1] = '0';
		game->character->x--;
		put_text(game);
	}
	else
		display_img(game, "tilesets_xpm/left2.xpm", x, y);
}

void	movedown_player(t_game_set *game)
{
	size_t	x;
	size_t	y;

	x = game->character->x;
	y = game->character->y;
	display_img(game, "tilesets_xpm/grass_2.xpm", x, y);
	if ((game->map[y + 1][x] == 'E' && check_col(game))
		|| (game->map[y + 1][x] == 'H'))
		exit(0);
	if (game->map[y + 1][x] != '1' && game->map[y + 1][x] != 'E')
	{
		display_img(game, "tilesets_xpm/grass_2.xpm", x, (y + 1));
		display_img(game, "tilesets_xpm/down2.xpm", x, (y + 1));
		if (game->map[y + 1][x] == 'C')
			game->map[y + 1][x] = '0';
		game->character->y++;
		put_text(game);
	}
	else
		display_img(game, "tilesets_xpm/down2.xpm", x, y);
}

void	moveright_player(t_game_set *game)
{
	size_t	x;
	size_t	y;

	x = game->character->x;
	y = game->character->y;
	display_img(game, "tilesets_xpm/grass_2.xpm", x, y);
	if ((game->map[y][x + 1] == 'E' && check_col(game))
		|| (game->map[y][x + 1] == 'H'))
		exit(0);
	if (game->map[y][x + 1] != '1' && game->map[y][x + 1] != 'E')
	{
		display_img(game, "tilesets_xpm/grass_2.xpm", (x + 1), y);
		display_img(game, "tilesets_xpm/right2.xpm", (x + 1), y);
		if (game->map[y][x + 1] == 'C')
			game->map[y][x + 1] = '0';
		game->character->x++;
		put_text(game);
	}
	else
		display_img(game, "tilesets_xpm/right2.xpm", x, y);
}
