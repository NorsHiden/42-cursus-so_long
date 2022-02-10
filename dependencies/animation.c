/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelidris <nelidris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 20:30:48 by nelidris          #+#    #+#             */
/*   Updated: 2022/02/08 21:18:04 by nelidris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	change_an(t_game_set *game, char *filenamegrass, char *filenameleg)
{
	size_t	x;
	size_t	y;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == 'C')
			{
				display_img(game, filenamegrass, x, y);
				display_img(game, filenameleg, x, y);
			}
			x++;
		}
		y++;
	}
}

int	col_an(t_game_set *game)
{
	static int	select_img;
	static int	count;

	if (count > 2000)
	{
		select_img = !select_img;
		if (select_img)
			change_an(game, "tilesets_xpm/grass_2.xpm", "tilesets_xpm/leg.xpm");
		else
			change_an(game, "tilesets_xpm/grass_2.xpm",
				"tilesets_xpm/legrotate.xpm");
		count = 0;
	}
	else
		count++;
	return (0);
}
