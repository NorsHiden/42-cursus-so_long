/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   displays.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelidris <nelidris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 20:29:50 by nelidris          #+#    #+#             */
/*   Updated: 2022/02/08 21:30:42 by nelidris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	display_img(t_game_set *game, char *filename, size_t x, size_t y)
{
	void	*img;

	img = mlx_xpm_file_to_image(game->mlx, filename,
			&game->width, &game->height);
	mlx_put_image_to_window(game->mlx, game->win,
		img, (x * 32), (y * 32));
	mlx_destroy_image(game->mlx, img);
}

void	put_tileset(t_game_set *game, size_t y, size_t x)
{
	if (x == 0 && y == 0)
		display_img(game, "tilesets_xpm/wall_left_up.xpm", x, y);
	else if (x == 0 && y > 0 && y < (ft_ptrlen(game->map) - 1))
		display_img(game, "tilesets_xpm/wall_left.xpm", x, y);
	else if (x > 0 && y == 0 && x < (ft_strlen((game->map)[0]) - 1))
		display_img(game, "tilesets_xpm/wall_mid_up.xpm", x, y);
	else if (x == (ft_strlen((game->map)[0]) - 1) && y == 0)
		display_img(game, "tilesets_xpm/wall_right_up.xpm", x, y);
	else if (x == (ft_strlen((game->map)[0]) - 1)
		&& y > 0 && y < (ft_ptrlen(game->map) - 1))
		display_img(game, "tilesets_xpm/wall_right.xpm", x, y);
	else if (y == (ft_ptrlen(game->map) - 1) && x == 0)
		display_img(game, "tilesets_xpm/wall_down_left.xpm", x, y);
	else if (y == (ft_ptrlen(game->map) - 1)
		&& x > 0 && x < (ft_strlen((game->map)[0]) - 1))
		display_img(game, "tilesets_xpm/wall_down.xpm", x, y);
	else if (y == (ft_ptrlen(game->map) - 1)
		&& x == (ft_strlen((game->map)[0]) - 1))
		display_img(game, "tilesets_xpm/wall_down_right.xpm", x, y);
	else if (x > 0 && x < (ft_strlen((game->map)[0]) - 1)
		&& y > 0 && y < ft_ptrlen(game->map) && game->map[y][x] == '1')
		display_img(game, "tilesets_xpm/box.xpm", x, y);
	else
		display_img(game, "tilesets_xpm/grass_2.xpm", x, y);
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
		{
			put_tileset(game, y, x);
			if (game->map[y][x] == 'E')
				display_img(game, "tilesets_xpm/door.xpm", x, y);
			else if (game->map[y][x] == 'H')
				display_img(game, "tilesets_xpm/hole.xpm", x, y);
			x++;
		}
		y++;
	}
}

void	display_character(t_game_set *game, t_character_set *character)
{
	void	*sprite;

	sprite = mlx_xpm_file_to_image(game->mlx,
			"tilesets_xpm/up2.xpm", &character->width, &character->height);
	mlx_put_image_to_window(game->mlx, game->win,
		sprite, (character->x * 32), (character->y * 32));
	mlx_destroy_image(game->mlx, sprite);
}
