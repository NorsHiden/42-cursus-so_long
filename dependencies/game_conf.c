/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_conf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelidris <nelidris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 20:28:51 by nelidris          #+#    #+#             */
/*   Updated: 2022/02/08 21:15:40 by nelidris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

t_game_set	*set_up_game(char **map, t_character_set *character)
{
	t_game_set	*game;
	size_t		width;
	size_t		height;

	width = ft_strlen(map[0]) * 32;
	height = ft_ptrlen(map) * 32;
	game = (t_game_set *)malloc(sizeof(t_game_set));
	if (!game)
		exit(1);
	game->mlx = mlx_init();
	game->map = map;
	game->count = 0;
	game->character = character;
	game->win = mlx_new_window(game->mlx, width, height, "so_long");
	return (game);
}

t_character_set	*set_up_character(char **map)
{
	t_character_set	*character;
	size_t			x;
	size_t			y;

	character = (t_character_set *)malloc(sizeof(t_character_set));
	if (!character)
		exit(1);
	x = 0;
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x] && map[y][x] != 'P')
			x++;
		if (map[y][x] == 'P')
			break ;
		y++;
	}
	if (!map[y])
		raise_error("Invalid map configuration.");
	character->x = x;
	character->y = y;
	return (character);
}
