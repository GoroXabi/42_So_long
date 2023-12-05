/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_movements.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xortega <xortega@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 10:01:19 by xortega           #+#    #+#             */
/*   Updated: 2023/11/28 12:08:11 by xortega          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	re_map_up(t_atributes *data)
{
	int	pl_t;
	int	current_tile;

	pl_t = gptl(data);
	current_tile = -1;
	while (data->tiles[++current_tile].tipe)
	{
		if (data->tiles[current_tile].y_cord == data->tiles[pl_t].y_cord - 1 && \
		data->tiles[current_tile].x_cord == data->tiles[pl_t].x_cord)
		{
			if (data->tiles[current_tile].tipe == '1')
				return ;
			else
				change_tile(data, current_tile, pl_t);
		}
	}
	data->steps++;
	if (data->coins == 0)
		data->exit_status = 1;
	ft_putnbr_fd(data->steps, 1);
	write(1, "\n", 1);
	draw_img(data, -1);
}

void	re_map_down(t_atributes *data)
{
	int	pl_t;
	int	current_tile;

	pl_t = gptl(data);
	current_tile = -1;
	while (data->tiles[++current_tile].tipe)
	{
		if (data->tiles[current_tile].y_cord == data->tiles[pl_t].y_cord + 1 && \
		data->tiles[current_tile].x_cord == data->tiles[pl_t].x_cord)
		{
			if (data->tiles[current_tile].tipe == '1')
				return ;
			else
				change_tile(data, current_tile, pl_t);
		}
	}
	data->steps++;
	if (data->coins == 0)
		data->exit_status = 1;
	ft_putnbr_fd(data->steps, 1);
	write(1, "\n", 1);
	draw_img(data, -1);
}

void	re_map_left(t_atributes *data)
{
	int	pl_t;
	int	current_tile;

	pl_t = gptl(data);
	current_tile = -1;
	while (data->tiles[++current_tile].tipe)
	{
		if (data->tiles[current_tile].x_cord == data->tiles[pl_t].x_cord - 1 && \
		data->tiles[current_tile].y_cord == data->tiles[pl_t].y_cord)
		{
			if (data->tiles[current_tile].tipe == '1')
				return ;
			else
				change_tile(data, current_tile, pl_t);
		}
	}
	data->steps++;
	if (data->coins == 0)
		data->exit_status = 1;
	ft_putnbr_fd(data->steps, 1);
	write(1, "\n", 1);
	draw_img(data, -1);
}

void	re_map_right(t_atributes *data)
{
	int	pl_t;
	int	current_tile;

	pl_t = gptl(data);
	current_tile = -1;
	while (data->tiles[++current_tile].tipe)
	{
		if (data->tiles[current_tile].x_cord == data->tiles[pl_t].x_cord + 1 && \
		data->tiles[current_tile].y_cord == data->tiles[pl_t].y_cord)
		{
			if (data->tiles[current_tile].tipe == '1')
				return ;
			else
				change_tile(data, current_tile, pl_t);
		}
	}
	data->steps++;
	if (data->coins == 0)
		data->exit_status = 1;
	ft_putnbr_fd(data->steps, 1);
	write(1, "\n", 1);
	draw_img(data, -1);
}
