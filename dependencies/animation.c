/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelidris <nelidris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 20:30:48 by nelidris          #+#    #+#             */
/*   Updated: 2022/02/19 14:53:36 by nelidris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	change_q_to_enemy(t_game_set *game)
{
	size_t	y;
	size_t	x;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == 'Q')
				game->map[y][x] = 'G';
			x++;
		}
		y++;
	}
}

int	game_animation(t_game_set *game)
{
	static int	count;

	if (game->game_status == DEFEAT)
		mlx_string_put(game->mlx, game->win,
			(((ft_strlen(game->map[0]) * 32) / 2) - 32),
			(((ft_ptrlen(game->map) * 32) / 2) - 16), 0x00Eb4034, "DEFEAT");
	else if (game->game_status == VICTORY)
		mlx_string_put(game->mlx, game->win,
			(((ft_strlen(game->map[0]) * 32) / 2) - 32),
			(((ft_ptrlen(game->map) * 32) / 2) - 16), 0x0077eb34, "VICTORY");
	else if (game->game_status == IN_GAME && count > 4000)
	{
		enemy_movement(game);
		change_q_to_enemy(game);
		display_rock(game);
		count = 0;
	}
	else
		count++;
	return (0);
}
