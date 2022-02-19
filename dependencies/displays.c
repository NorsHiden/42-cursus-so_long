/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   displays.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelidris <nelidris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 20:29:50 by nelidris          #+#    #+#             */
/*   Updated: 2022/02/19 10:13:05 by nelidris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	display_img(t_game_set *game, char *filename, size_t x, size_t y)
{
	void	*img;
	int		width;
	int		height;

	img = mlx_xpm_file_to_image(game->mlx, filename,
			&width, &height);
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
				display_img(game, "tilesets_xpm/rock.xpm", x, y - 1);
			x++;
		}
		y++;
	}
	return (0);
}

void	display_character(t_game_set *game, t_character_set *character)
{
	void	*sprite;
	int		width;
	int		height;

	sprite = mlx_xpm_file_to_image(game->mlx,
			"tilesets_xpm/up.xpm", &width, &height);
	mlx_put_image_to_window(game->mlx, game->win,
		sprite, (character->x * 32), (character->y * 32));
	mlx_destroy_image(game->mlx, sprite);
}
