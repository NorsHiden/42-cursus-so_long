/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   displays.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelidris <nelidris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 20:29:50 by nelidris          #+#    #+#             */
/*   Updated: 2022/03/16 08:26:59 by nelidris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	display_img(t_game_set *game, void *img, size_t x, size_t y)
{
	mlx_put_image_to_window(game->mlx, game->win,
		img, (x * 32), (y * 32));
}

void	put_tileset(t_game_set *game, size_t y, size_t x)
{
	if (x == 0 && y == 0)
		display_img(game, game->tiles.wall_left_up, x, y);
	else if (x == 0 && y > 0 && y < (ft_ptrlen(game->map) - 1))
		display_img(game, game->tiles.wall_left, x, y);
	else if (x > 0 && y == 0 && x < (ft_strlen((game->map)[0]) - 1))
		display_img(game, game->tiles.wall_mid_up, x, y);
	else if (x == (ft_strlen((game->map)[0]) - 1) && y == 0)
		display_img(game, game->tiles.wall_right_up, x, y);
	else if (x == (ft_strlen((game->map)[0]) - 1)
		&& y > 0 && y < (ft_ptrlen(game->map) - 1))
		display_img(game, game->tiles.wall_right, x, y);
	else if (y == (ft_ptrlen(game->map) - 1) && x == 0)
		display_img(game, game->tiles.wall_down_left, x, y);
	else if (y == (ft_ptrlen(game->map) - 1)
		&& x > 0 && x < (ft_strlen((game->map)[0]) - 1))
		display_img(game, game->tiles.wall_down, x, y);
	else if (y == (ft_ptrlen(game->map) - 1)
		&& x == (ft_strlen((game->map)[0]) - 1))
		display_img(game, game->tiles.wall_down_right, x, y);
	else
		display_img(game, game->tiles.grass, x, y);
}

void	display_map(t_game_set *game)
{
	size_t	y;
	size_t	x;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
			put_tileset(game, y, x++);
		y++;
	}
}

int	display_rock(t_game_set *game)
{
	size_t	y;
	size_t	x;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (x > 0 && x < (ft_strlen((game->map)[0]) - 1)
				&& y > 0 && y < (ft_ptrlen(game->map) - 1)
				&& game->map[y][x] == '1')
				display_img(game, game->tiles.rock, x, y - 1);
			x++;
		}
		y++;
	}
	return (0);
}
