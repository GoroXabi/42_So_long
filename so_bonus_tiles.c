/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_bonus_tiles.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xortega <xortega@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 11:52:02 by xortega           #+#    #+#             */
/*   Updated: 2023/11/30 14:37:33 by xortega          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	coin_counter(t_atributes *data)
{
	int	current_tile;

	current_tile = -1;
	while (data->tiles[++current_tile].tipe)
	{
		if (data->tiles[current_tile].tipe == 'C')
			data->coins++;
	}
}

void	init_tiles(t_atributes *data, int arrow, int c_tile)
{
	int	current_x;
	int	current_y;

	data->tiles = malloc(sizeof(t_tiles) * data->total_tiles + 1);
	if (!data->tiles)
		error_manager("MALLOC FAILED");
	data->tiles[data->total_tiles].tipe = '\0';
	current_x = 0;
	current_y = 0;
	while (c_tile < data->total_tiles)
	{
		if (data->raw_map[arrow] == '\n' && data->raw_map[arrow + 1])
		{
			arrow++;
			current_x = 0;
			current_y++;
		}
		data->tiles[c_tile].tipe = data->raw_map[arrow];
		data->tiles[c_tile].x_cord = current_x;
		data->tiles[c_tile].y_cord = current_y;
		current_x++;
		arrow++;
		c_tile++;
	}
}

int	gptl(t_atributes *data)
{
	int	current_tile;

	current_tile = -1;
	while (data->tiles[++current_tile].tipe)
	{
		if (data->tiles[current_tile].tipe == 'P' \
		|| data->tiles[current_tile].tipe == 'K')
			return (current_tile);
	}
	return (0);
}

void	fill(t_atributes *data, int first_x, int first_y)
{
	int	current_tile;

	current_tile = -1;
	while (data->tiles[++current_tile].tipe)
	{
		if (data->tiles[current_tile].x_cord == first_x
			&& data->tiles[current_tile].y_cord == first_y)
		{
			if (data->tiles[current_tile].tipe == '1')
				break ;
			else
			{
				data->tiles[current_tile].tipe = '1';
				fill(data, data->tiles[current_tile].x_cord + 1, \
				data->tiles[current_tile].y_cord);
				fill(data, data->tiles[current_tile].x_cord, \
				data->tiles[current_tile].y_cord + 1);
				fill(data, data->tiles[current_tile].x_cord - 1, \
				data->tiles[current_tile].y_cord);
				fill(data, data->tiles[current_tile].x_cord, \
				data->tiles[current_tile].y_cord - 1);
			}
		}
	}
}

void	copy_atributes(t_atributes *data, t_atributes *copy)
{
	int	c_tile;

	copy->tiles = malloc(sizeof(t_tiles) * data->total_tiles + 1);
	if (!copy->tiles)
		error_manager("MALLOC FAILED");
	copy->tiles[data->total_tiles].tipe = '\0';
	c_tile = -1;
	while (data->tiles[++c_tile].tipe)
	{
		copy->tiles[c_tile].tipe = data->tiles[c_tile].tipe;
		copy->tiles[c_tile].x_cord = data->tiles[c_tile].x_cord;
		copy->tiles[c_tile].y_cord = data->tiles[c_tile].y_cord;
	}
}
