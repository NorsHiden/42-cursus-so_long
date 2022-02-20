/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelidris <nelidris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 20:33:00 by nelidris          #+#    #+#             */
/*   Updated: 2022/02/20 07:09:53 by nelidris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

size_t	ft_ptrlen(char **str)
{
	size_t	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

int	check_col(t_game_set *game)
{
	int	y;
	int	x;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == 'C')
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}

void	put_text(t_game_set *game)
{
	char	*str;
	size_t	x;

	x = 1;
	while (x < 5)
		display_img(game, "tilesets_xpm/wall_mid_up.xpm", x++, 0);
	str = ft_itoa(game->count++);
	mlx_string_put(game->mlx, game->win, 32, 0, 0x00ffffff, str);
	free(str);
}
