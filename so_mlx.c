/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_mlx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xortega <xortega@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 10:54:22 by xortega           #+#    #+#             */
/*   Updated: 2023/12/04 13:55:36 by xortega          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_img(t_atributes *data, int c_t)
{
	while (data->tiles[++c_t].tipe)
	{
		if (data->tiles[c_t].tipe == '1')
			mlx_put_image_to_window(data->mlx.ptr, data->mlx.window, data->mlx.\
		wall, (data->tiles[c_t].x_cord * 40), (data->tiles[c_t].y_cord) * 80);
		if (data->tiles[c_t].tipe == '0')
			mlx_put_image_to_window(data->mlx.ptr, data->mlx.window, data->mlx.\
		floor, (data->tiles[c_t].x_cord * 40), (data->tiles[c_t].y_cord) * 80);
		if (data->tiles[c_t].tipe == 'P')
			mlx_put_image_to_window(data->mlx.ptr, data->mlx.window, data->mlx.\
			p, (data->tiles[c_t].x_cord * 40), (data->tiles[c_t].y_cord) * 80);
		if (data->tiles[c_t].tipe == 'C')
			mlx_put_image_to_window(data->mlx.ptr, data->mlx.window, data->mlx.\
			c, (data->tiles[c_t].x_cord * 40), (data->tiles[c_t].y_cord) * 80);
		if (data->tiles[c_t].tipe == 'E')
			mlx_put_image_to_window(data->mlx.ptr, data->mlx.window, data->mlx.\
			e, (data->tiles[c_t].x_cord * 40), (data->tiles[c_t].y_cord) * 80);
		if (data->tiles[c_t].tipe == 'K')
			mlx_put_image_to_window(data->mlx.ptr, data->mlx.window, data->mlx.\
			k, (data->tiles[c_t].x_cord * 40), (data->tiles[c_t].y_cord) * 80);
	}
}

void	mlx_get_textures(t_atributes *data)
{
	int	a;
	int	b;

	data->mlx.wall = mlx_xpm_file_to_image(\
	data->mlx.ptr, "textures/1.xpm", &a, &b);
	data->mlx.floor = mlx_xpm_file_to_image(\
	data->mlx.ptr, "textures/0.xpm", &a, &b);
	data->mlx.p = mlx_xpm_file_to_image(\
	data->mlx.ptr, "textures/P.xpm", &a, &b);
	data->mlx.c = mlx_xpm_file_to_image(\
	data->mlx.ptr, "textures/C.xpm", &a, &b);
	data->mlx.e = mlx_xpm_file_to_image(\
	data->mlx.ptr, "textures/E.xpm", &a, &b);
	data->mlx.k = mlx_xpm_file_to_image(\
	data->mlx.ptr, "textures/K.xpm", &a, &b);
}

void	change_tile(t_atributes *data, int obj_t, int pl_t)
{
	if (data->tiles[obj_t].tipe == 'E' && data->coins == 0)
		win(data);
	if (data->tiles[obj_t].tipe == 'E' && data->coins > 0)
	{
		data->tiles[obj_t].tipe = 'K';
		data->tiles[pl_t].tipe = '0';
	}
	if (data->tiles[obj_t].tipe == '0')
	{
		data->tiles[obj_t]. tipe = 'P';
		if (data->tiles[pl_t].tipe == 'K')
			data->tiles[pl_t].tipe = 'E';
		else
			data->tiles[pl_t].tipe = '0';
	}
	if (data->tiles[obj_t].tipe == 'C')
	{
		data->coins--;
		data->tiles[obj_t]. tipe = 'P';
		if (data->tiles[pl_t].tipe == 'K')
			data->tiles[pl_t].tipe = 'E';
		else
			data->tiles[pl_t].tipe = '0';
	}
}

int	key_hook(int keycode, t_atributes *data)
{
	if (keycode == 53)
		real_free(data);
	if (keycode == 13)
		re_map_up(data);
	if (keycode == 1)
		re_map_down(data);
	if (keycode == 0)
		re_map_left(data);
	if (keycode == 2)
		re_map_right(data);
	return (keycode);
}

void	mlx_start(t_atributes *data)
{
	data->mlx.ptr = mlx_init();
	data->mlx.window = mlx_new_window(data->mlx.ptr, \
	(data->wide * 40), (data->tall * 80), "So_long");
	mlx_get_textures(data);
	draw_img(data, -1);
	mlx_key_hook(data->mlx.window, key_hook, data);
	mlx_hook(data->mlx.window, 17, 0, real_free, data);
	mlx_loop(data->mlx.ptr);
	exit(0);
}
