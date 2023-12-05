/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_bonus_exits.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xortega <xortega@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 10:33:30 by xortega           #+#    #+#             */
/*   Updated: 2023/11/30 14:37:13 by xortega          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	error_manager(char *error)
{
	write(1, "\033[1;31m", 7);
	write(1, "ERROR: ", 7);
	ft_putstr_fd(error, 1);
	write(1, "\n", 1);
	exit(2);
}

void	check_doubles_error(int p_count, int e_count, int c_count)
{
	if (p_count < 1)
		error_manager("U NEED A PLAYER FOLK");
	if (p_count > 1)
		error_manager("NOT MULTIPLAYER");
	if (e_count < 1)
		error_manager("THERE IS NO ESCAPE");
	if (e_count > 1)
		error_manager("TOO MANY EXITS DON'T YA THINK?");
	if (c_count < 1)
		error_manager("THAT EXIT NEEDS A KEY");
}

int	real_free(t_atributes *data)
{
	if (data->tiles)
		free(data->tiles);
	if (data->raw_map)
		free(data->raw_map);
	if (data->mlx.window)
		mlx_destroy_window(data->mlx.ptr, data->mlx.window);
	if (data->mlx.wall)
		mlx_destroy_image(data->mlx.ptr, data->mlx.wall);
	if (data->mlx.floor)
		mlx_destroy_image(data->mlx.ptr, data->mlx.floor);
	if (data->mlx.p)
		mlx_destroy_image(data->mlx.ptr, data->mlx.p);
	if (data->mlx.c)
		mlx_destroy_image(data->mlx.ptr, data->mlx.c);
	if (data->mlx.e)
		mlx_destroy_image(data->mlx.ptr, data->mlx.e);
	animation_close(data);
	write (1, "goob bye\n", 9);
	exit(0);
}

void	correct_file(const char *map_path)
{
	int	path_len;

	path_len = ft_strlen(map_path);
	if (map_path[path_len - 1] == 'r' \
	&& map_path[path_len - 2] == 'e' \
	&& map_path[path_len - 3] == 'b' \
	&& map_path[path_len - 4] == '.')
		return ;
	else
		error_manager("NOT A .ber");
}

void	win(t_atributes *data)
{
	write(1, "YOU WIN\n", 8);
	real_free(data);
}
