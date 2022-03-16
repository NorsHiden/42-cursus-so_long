/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_directions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelidris <nelidris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 20:27:38 by nelidris          #+#    #+#             */
/*   Updated: 2022/02/19 10:10:23 by nelidris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	moveup_player(t_game_set *game)
{
	size_t	x;
	size_t	y;

	x = game->character->x;
	y = game->character->y;
	display_img(game, game->tiles.grass, x, y);
	if (game->map[y - 1][x] == 'E' && check_col(game))
		game->game_status = VICTORY;
	else if ((game->map[y - 1][x] == '0' || game->map[y - 1][x] == 'C')
		&& game->map[y - 1][x] != 'E')
	{
		display_img(game, game->tiles.grass, x, (y - 1));
		display_img(game, game->tiles.playerup, x, (y - 1));
		game->map[y - 1][x] = 'P';
		game->map[y][x] = '0';
		game->character->y--;
		put_text(game);
	}
	else
		display_img(game, game->tiles.playerup, x, y);
}

void	moveleft_player(t_game_set *game)
{
	size_t	x;
	size_t	y;

	x = game->character->x;
	y = game->character->y;
	display_img(game, game->tiles.grass, x, y);
	if (game->map[y][x - 1] == 'E' && check_col(game))
		game->game_status = VICTORY;
	else if ((game->map[y][x - 1] == '0' || game->map[y][x - 1] == 'C')
		&& game->map[y][x - 1] != 'E')
	{
		display_img(game, game->tiles.grass, (x - 1), y);
		display_img(game, game->tiles.playerleft, (x - 1), y);
		game->map[y][x - 1] = 'P';
		game->map[y][x] = '0';
		game->character->x--;
		put_text(game);
	}
	else
		display_img(game, game->tiles.playerleft, x, y);
}

void	movedown_player(t_game_set *game)
{
	size_t	x;
	size_t	y;

	x = game->character->x;
	y = game->character->y;
	display_img(game, game->tiles.grass, x, y);
	if (game->map[y + 1][x] == 'E' && check_col(game))
		game->game_status = VICTORY;
	if ((game->map[y + 1][x] == '0' || game->map[y + 1][x] == 'C')
		&& game->map[y + 1][x] != 'E')
	{
		display_img(game, game->tiles.grass, x, (y + 1));
		display_img(game, game->tiles.playerdown, x, (y + 1));
		game->map[y + 1][x] = 'P';
		game->map[y][x] = '0';
		game->character->y++;
		put_text(game);
	}
	else
		display_img(game, game->tiles.playerdown, x, y);
}

void	moveright_player(t_game_set *game)
{
	size_t	x;
	size_t	y;

	x = game->character->x;
	y = game->character->y;
	display_img(game, game->tiles.grass, x, y);
	if (game->map[y][x + 1] == 'E' && check_col(game))
		game->game_status = VICTORY;
	if ((game->map[y][x + 1] == '0' || game->map[y][x + 1] == 'C')
		&& game->map[y][x + 1] != 'E')
	{
		display_img(game, game->tiles.grass, (x + 1), y);
		display_img(game, game->tiles.playerright, (x + 1), y);
		game->map[y][x + 1] = 'P';
		game->map[y][x] = '0';
		game->character->x++;
		put_text(game);
	}
	else
		display_img(game, game->tiles.playerright, x, y);
}
