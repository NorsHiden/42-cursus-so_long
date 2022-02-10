/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launcher.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelidris <nelidris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 11:47:03 by nelidris          #+#    #+#             */
/*   Updated: 2022/02/08 21:15:42 by nelidris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_close(void *param)
{
	(void)param;
	exit(0);
	return (0);
}

int	keycode(int keycode, t_game_set *game)
{
	if (keycode == 13)
		moveup_player(game);
	else if (keycode == 0)
		moveleft_player(game);
	else if (keycode == 2)
		moveright_player(game);
	else if (keycode == 1)
		movedown_player(game);
	else if (keycode == 53)
		exit(0);
	return (0);
}

void	launch_game(char **map)
{
	t_game_set		*game;
	t_character_set	*character;

	character = set_up_character(map);
	game = set_up_game(map, character);
	display_map(game);
	display_character(game, character);
	mlx_hook(game->win, 17, 0, ft_close, &game->width);
	mlx_loop_hook(game->mlx, col_an, game);
	mlx_hook(game->win, 2, 0, keycode, game);
	put_text(game);
	mlx_loop(game->mlx);
}
