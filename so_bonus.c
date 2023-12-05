/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_bonus.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xortega <xortega@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 14:10:08 by xortega           #+#    #+#             */
/*   Updated: 2023/11/30 14:37:39 by xortega          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	draw_text(t_atributes *data)
{
	int		color;
	char	*steps;
	char	*coins;

	steps = ft_itoa(data->steps);
	coins = ft_itoa(data->coins);
	srand(time(NULL) + rand());
	color = ((rand() % (16777215 - 1118481)) + 1118481);
	mlx_string_put(data->mlx.ptr, data->mlx.window,
		10, 10, color, "steps: ");
	mlx_string_put(data->mlx.ptr, data->mlx.window,
		60, 10, color, steps);
	mlx_string_put(data->mlx.ptr, data->mlx.window,
		100, 10, color, "coins left: ");
	mlx_string_put(data->mlx.ptr, data->mlx.window,
		180, 10, color, coins);
	free(steps);
	free(coins);
}

int	animation(t_atributes *data)
{
	int	a;
	int	b;

	if (data->coins > 0)
	{
		mlx_destroy_image(data->mlx.ptr, data->mlx.c);
		c_bonus_animation(data);
		data->mlx.c = mlx_xpm_file_to_image(\
		data->mlx.ptr, "textures/C.xpm", &a, &b);
		draw_img(data, -1);
		return (0);
	}
	mlx_destroy_image(data->mlx.ptr, data->mlx.p);
	p_bonus_animation(data);
	data->mlx.p = mlx_xpm_file_to_image(\
	data->mlx.ptr, "textures/P.xpm", &a, &b);
	draw_img(data, -1);
	return (0);
}

void	animation_close(t_atributes *data)
{
	if (data->mlx.p_sprite)
	{
		p_change_hexa(data->mlx.p_sprite, "000000");
		pwrite(data->mlx.p_sprite_fd, data->mlx.p_sprite, 4283, 0);
		close(data->mlx.p_sprite_fd);
	}
	if (data->mlx.c_sprite)
	{
		c_change_hexa(data->mlx.c_sprite, "000000");
		pwrite(data->mlx.c_sprite_fd, data->mlx.c_sprite, 4358, 0);
		close(data->mlx.c_sprite_fd);
	}
}
