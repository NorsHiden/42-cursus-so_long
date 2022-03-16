/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xpm_to_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelidris <nelidris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 10:22:20 by nelidris          #+#    #+#             */
/*   Updated: 2022/03/16 08:27:56 by nelidris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	player_tiles(t_game_set *game)
{
	game->tiles.playerup = mlx_xpm_file_to_image(game->mlx,
			"tilesets_xpm/up.xpm", &game->width, &game->height);
	game->tiles.playerdown = mlx_xpm_file_to_image(game->mlx,
			"tilesets_xpm/down.xpm", &game->width, &game->height);
	game->tiles.playerright = mlx_xpm_file_to_image(game->mlx,
			"tilesets_xpm/right.xpm", &game->width, &game->height);
	game->tiles.playerleft = mlx_xpm_file_to_image(game->mlx,
			"tilesets_xpm/left.xpm", &game->width, &game->height);
}

static void	enemy_tiles(t_game_set *game)
{
	game->tiles.enemyup = mlx_xpm_file_to_image(game->mlx,
			"tilesets_xpm/enup.xpm", &game->width, &game->height);
	game->tiles.enemydown = mlx_xpm_file_to_image(game->mlx,
			"tilesets_xpm/endown.xpm", &game->width, &game->height);
	game->tiles.enemyright = mlx_xpm_file_to_image(game->mlx,
			"tilesets_xpm/enright.xpm", &game->width, &game->height);
	game->tiles.enemyleft = mlx_xpm_file_to_image(game->mlx,
			"tilesets_xpm/enleft.xpm", &game->width, &game->height);
}

static void	walls_tiles(t_game_set *game)
{
	game->tiles.wall_left_up = mlx_xpm_file_to_image(game->mlx,
			"tilesets_xpm/wall_left_up.xpm", &game->width, &game->height);
	game->tiles.wall_left = mlx_xpm_file_to_image(game->mlx,
			"tilesets_xpm/wall_left.xpm", &game->width, &game->height);
	game->tiles.wall_mid_up = mlx_xpm_file_to_image(game->mlx,
			"tilesets_xpm/wall_mid_up.xpm", &game->width, &game->height);
	game->tiles.wall_right_up = mlx_xpm_file_to_image(game->mlx,
			"tilesets_xpm/wall_right_up.xpm", &game->width, &game->height);
	game->tiles.wall_right = mlx_xpm_file_to_image(game->mlx,
			"tilesets_xpm/wall_right.xpm", &game->width, &game->height);
	game->tiles.wall_down_left = mlx_xpm_file_to_image(game->mlx,
			"tilesets_xpm/wall_down_left.xpm", &game->width, &game->height);
	game->tiles.wall_down = mlx_xpm_file_to_image(game->mlx,
			"tilesets_xpm/wall_down.xpm", &game->width, &game->height);
	game->tiles.wall_down_right = mlx_xpm_file_to_image(game->mlx,
			"tilesets_xpm/wall_down_right.xpm", &game->width, &game->height);
}

void	config_tiles(t_game_set *game)
{
	player_tiles(game);
	enemy_tiles(game);
	walls_tiles(game);
	game->tiles.grass = mlx_xpm_file_to_image(game->mlx,
			"tilesets_xpm/grass_2.xpm", &game->width, &game->height);
	game->tiles.rock = mlx_xpm_file_to_image(game->mlx,
			"tilesets_xpm/rock.xpm", &game->width, &game->height);
	game->tiles.collectible = mlx_xpm_file_to_image(game->mlx,
			"tilesets_xpm/jewelry.xpm", &game->width, &game->height);
	game->tiles.door = mlx_xpm_file_to_image(game->mlx,
			"tilesets_xpm/door.xpm", &game->width, &game->height);
}
