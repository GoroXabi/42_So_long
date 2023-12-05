/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_bonus_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xortega <xortega@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 09:58:44 by xortega           #+#    #+#             */
/*   Updated: 2023/12/04 13:29:34 by xortega          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	get_map_size(t_atributes *data, const char *map_path)
{
	char	*buffer;
	int		map_size;
	int		map_fd;
	int		map_rtn;

	map_fd = open(map_path, O_RDONLY);
	if (map_fd < 0)
		error_manager("FILE OPEN ERROR");
	buffer = malloc(sizeof(char) * 2);
	if (!buffer)
		error_manager("MALLOC FAILED");
	buffer[1] = '\0';
	map_rtn = 1;
	map_size = 0;
	while (map_rtn > 0)
	{
		map_rtn = read(map_fd, buffer, 1);
		map_size++;
	}
	close(map_fd);
	free(buffer);
	if (map_size < 16)
		error_manager("NOT LARGUE ENOUGTH MAP");
	data->map_size = map_size - 1;
}

void	map_wide(t_atributes *data)
{
	int	arrow;
	int	tiles_nl;
	int	expected_tiles;

	expected_tiles = 1;
	while (data->raw_map[expected_tiles] != '\n')
		expected_tiles++;
	arrow = 0;
	tiles_nl = 1;
	while (data->raw_map[arrow])
	{
		if (data->raw_map[arrow] == '\n' && data->raw_map[arrow + 1])
		{
			if (tiles_nl != expected_tiles + 1)
				error_manager("MAP IS NOT RECTANGULAR");
			tiles_nl = 0;
		}
		tiles_nl++;
		arrow++;
	}
	if (tiles_nl != expected_tiles + 1 && data->raw_map[arrow - 1] != '\n')
		error_manager("MAP IS NOT RECTANGULAR");
	if (expected_tiles < 0)
		error_manager("INVALID MAP");
	data->wide = expected_tiles;
}

void	map_tall(t_atributes *data)
{
	int	arrow;
	int	tall;

	arrow = 0;
	tall = 0;
	while (data->raw_map[arrow])
	{
		if (data->raw_map[arrow] == '\n')
			tall++;
		arrow++;
	}
	if (data->raw_map[arrow - 2] == '1')
		tall++;
	if (data->raw_map[data->map_size - 1] == '\n')
		tall--;
	data->tall = tall;
}

void	init_map_data(t_atributes *data)
{
	map_wide(data);
	map_tall(data);
	data->total_tiles = (data->wide * data->tall);
	if (data->total_tiles < 15)
		error_manager("NOT LARGE ENOUGTH MAP");
}

void	get_raw_map(t_atributes *data, const char *map_path)
{
	int		map_fd;

	correct_file(map_path);
	get_map_size(data, map_path);
	map_fd = open(map_path, O_RDONLY);
	data->raw_map = malloc(sizeof(char) * (data->map_size + 1));
	if (!data->raw_map)
		error_manager("MALLOC FAILED");
	read(map_fd, data->raw_map, data->map_size);
	data->raw_map[data->map_size] = '\0';
	close(map_fd);
}
