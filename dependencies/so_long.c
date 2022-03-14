/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelidris <nelidris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 17:27:23 by nelidris          #+#    #+#             */
/*   Updated: 2022/03/09 13:18:23 by nelidris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static char	**split_map(char *map)
{
	char	**splitted_map;

	splitted_map = ft_split(map, '\n');
	free(map);
	if (!splitted_map)
		return (0);
	if (valid_map_size(splitted_map))
		raise_error("Invalid map configuration.\n");
	return (splitted_map);
}

char	**import_map(int fd)
{
	char	*tmp;
	char	*buffer;
	char	*map;
	ssize_t	eof;

	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	map = ft_strdup("");
	if (!buffer || !map)
		exit(1);
	eof = 1;
	while (eof)
	{
		eof = read(fd, buffer, BUFFER_SIZE);
		buffer[eof] = 0;
		tmp = map;
		map = ft_strjoin(map, buffer);
		if (!map)
			exit(1);
		free(tmp);
	}
	free(buffer);
	if (!*map || valid_characters(map) || valid_map_conf(map))
		raise_error("Invalid map configuration.\n");
	return (split_map(map));
}

int	valid_map_space(char **map)
{
	size_t	y;
	size_t	x;

	x = 0;
	while (map[0][x] == '1')
		x++;
	if (map[0][x])
		return (1);
	y = 1;
	while (y < ft_ptrlen(map) - 1)
	{
		x = ft_strlen(map[y]) - 1;
		if (map[y][0] != '1' || map[y][x] != '1')
			return (1);
		y++;
	}
	x = 0;
	while (map[y][x] == '1')
		x++;
	if (map[y][x])
		return (1);
	return (0);
}

int	main(int c, char **v)
{
	char	**map;
	int		fd;

	if (c != 2 || valid_map(v[1]))
		raise_error("Invalid arguments.\n");
	fd = open(v[1], O_RDONLY);
	if (fd < 0)
		return (0);
	map = import_map(fd);
	if (!map)
		exit(1);
	if (valid_map_space(map))
		raise_error("Invalid map configurations.\n");
	close(fd);
	launch_game(map);
	return (0);
}
