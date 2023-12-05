/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_bonus_long.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xortega <xortega@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 16:29:42 by xortega           #+#    #+#             */
/*   Updated: 2023/12/04 13:17:49 by xortega          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	init(t_atributes *data)
{
	data->mlx.p_sprite = NULL;
	data->mlx.c_sprite = NULL;
	data->mlx.wall = NULL;
	data->mlx.floor = NULL;
	data->mlx.p = NULL;
	data->mlx.c = NULL;
	data->mlx.e = NULL;
	data->mlx.k = NULL;
	data->mlx.ptr = NULL;
	data->mlx.window = NULL;
	data->mlx.c_sprite_fd = 0;
	data->mlx.p_sprite_fd = 0;
	data->tiles = NULL;
	data->map_size = 0;
	data->coins = 0;
	data->steps = 0;
	data->total_tiles = 0;
	data->wide = 0;
	data->tall = 0;
	data->exit_status = 0;
}

int	main(int argc, char const *argv[])
{
	t_atributes	data;

	if (argc < 2)
		error_manager("PLS INSERT A MAP PATH");
	init(&data);
	get_raw_map(&data, argv[1]);
	init_map_data(&data);
	init_tiles(&data, 0, 0);
	coin_counter(&data);
	map_check(&data);
	mlx_start(&data);
	real_free(&data);
	return (0);
}
