/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xortega <xortega@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 16:33:55 by xortega           #+#    #+#             */
/*   Updated: 2023/11/30 14:39:00 by xortega          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include <fcntl.h>
# include <time.h>
# include "Libft/libft.h"
# include "mlx/mlx.h"

typedef struct tiles
{
	char	tipe;
	int		x_cord;
	int		y_cord;
}					t_tiles;

typedef struct mlx_data
{
	void	*wall;
	void	*floor;
	void	*p;
	void	*c;
	void	*e;
	void	*k;
	void	*ptr;
	void	*window;
	char	*c_sprite;
	char	*p_sprite;
	int		c_sprite_fd;
	int		p_sprite_fd;
}					t_mlx_data;

typedef struct atributes
{
	int			steps;
	int			coins;
	int			map_size;
	int			total_tiles;
	int			wide;
	int			tall;
	int			exit_status;
	char		*raw_map;
	t_tiles		*tiles;
	t_mlx_data	mlx;
}					t_atributes;

/*
MAP CHECK AND PARSE
*/
void	init_map_data(t_atributes *data);
void	get_raw_map(t_atributes *data, const char *map_path);
void	get_map_size(t_atributes *data, const char *map_path);
void	map_tall(t_atributes *data);
void	map_wide(t_atributes *data);
/*
CONVERTING MAP TO TILE OBJS
*/
void	coin_counter(t_atributes *data);
void	init_tiles(t_atributes *data, int arrow, int c_tile);
void	fill(t_atributes *data, int first_x, int first_y);
void	copy_atributes(t_atributes *data, t_atributes *copy);
int		gptl(t_atributes *data);
/*
CHECKING THINGS
*/
void	map_check(t_atributes *atributes);
void	check_fill(t_atributes *data);
void	check_caracters(t_atributes *data);
void	check_doubles(t_atributes *data);
void	check_walls(t_atributes *data);
/*
MLX STUFF
*/
void	mlx_start(t_atributes *data);
int		key_hook(int keycode, t_atributes *data);
void	change_tile(t_atributes *data, int obj_t, int pl_t);
void	mlx_get_textures(t_atributes *data);
void	draw_img(t_atributes *data, int current_tile);
/*
MOVEMENTS
*/
void	re_map_right(t_atributes *data);
void	re_map_left(t_atributes *data);
void	re_map_down(t_atributes *data);
void	re_map_up(t_atributes *data);
/*
EXIT MANAGMENT
*/
void	error_manager(char *error);
void	check_doubles_error(int p_count, int e_count, int c_count);
int		real_free(t_atributes *data);
void	win(t_atributes *data);
void	correct_file(const char *map_path);
/*
BONUS
*/
void	animation_close(t_atributes *data);
int		animation(t_atributes *data);
void	draw_text(t_atributes *data);
/*
BONUS_P
*/
char	*p_make_hex(int num, int arrow);
void	p_bonus_animation(t_atributes *data);
void	p_change_sprite(char *sprite, int sprite_fd);
void	p_change_hexa(char *sprite, char *new_exa);
/*
BONUS_C
*/
char	*c_make_hex(int num, int arrow);
void	c_bonus_animation(t_atributes *data);
void	c_change_sprite(char *sprite, int sprite_fd);
void	c_change_hexa(char *sprite, char *new_exa);

#endif
