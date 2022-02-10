/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelidris <nelidris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 13:07:44 by nelidris          #+#    #+#             */
/*   Updated: 2022/02/09 11:17:37 by nelidris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	valid_map(char *path)
{
	int	len_path;

	len_path = ft_strlen(path);
	if (len_path < 5)
		return (1);
	if (ft_strncmp(".ber", &path[len_path - 4], 3)
		|| !ft_strncmp(".ber", path, 3))
		return (1);
	return (0);
}

int	valid_characters(char *map)
{
	char	*player;

	player = ft_strchr(map, 'P');
	if (!player)
		return (1);
	if (ft_strchr((player + 1), 'P'))
		return (1);
	if (!ft_strchr(map, 'C') || !ft_strchr(map, 'E'))
		return (1);
	return (0);
}

int	valid_map_size(char **map)
{
	size_t	def_len;
	int		i;

	def_len = ft_strlen(map[0]);
	i = 1;
	while (map[i] && def_len == ft_strlen(map[i]))
		i++;
	if (map[i])
		return (1);
	return (0);
}

int	valid_map_conf(char *map)
{
	int	i;

	i = 0;
	if (map[i] == '\n')
		return (1);
	while ((map[i] == 'P' || map[i] == '1' || map[i] == '0'
			|| map[i] == 'E' || map[i] == 'C' || map[i] == 'H'
			|| map[i] == '\n') && map[i])
	{
		if (map[i] == '\n' && map[i + 1] == '\n')
			return (1);
		i++;
	}
	if (map[i] || map[i - 1] == '\n')
		return (1);
	return (0);
}
