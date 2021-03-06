/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launcher.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelidris <nelidris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 11:47:03 by nelidris          #+#    #+#             */
/*   Updated: 2022/03/16 08:35:42 by nelidris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_close(void)
{
	exit(0);
	return (0);
}

int	keycode(int keycode, t_game_set *game)
{
	if (game->game_status == IN_GAME && keycode == 13)
		moveup_player(game);
	else if (game->game_status == IN_GAME && keycode == 0)
		moveleft_player(game);
	else if (game->game_status == IN_GAME && keycode == 2)
		moveright_player(game);
	else if (game->game_status == IN_GAME && keycode == 1)
		movedown_player(game);
	else if (keycode == 53)
		exit(0);
	if (game->game_status == IN_GAME)
		display_rock(game);
	return (0);
}

void	display_mobs(t_game_set *game)
{
	size_t	y;
	size_t	x;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == 'G')
				display_img(game, game->tiles.enemydown, x, y);
			else if (game->map[y][x] == 'C')
				display_img(game, game->tiles.collectible, x, y);
			else if (game->map[y][x] == 'E')
				display_img(game, game->tiles.door, x, y);
			x++;
		}
		y++;
	}
}

void	launch_game(char **map)
{
	t_game_set		*game;
	t_character_set	*character;

	character = set_up_character(map);
	game = set_up_game(map, character);
	config_tiles(game);
	display_map(game);
	display_img(game, game->tiles.playerup,
		game->character->x, game->character->y);
	display_mobs(game);
	display_rock(game);
	mlx_hook(game->win, 17, 0, ft_close, NULL);
	mlx_loop_hook(game->mlx, game_animation, game);
	mlx_hook(game->win, 2, 0, keycode, game);
	put_text(game);
	mlx_loop(game->mlx);
}
