/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_bonus_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xortega <xortega@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 12:27:44 by xortega           #+#    #+#             */
/*   Updated: 2023/11/30 14:37:31 by xortega          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	p_change_hexa(char *sprite, char *new_exa)
{
	int	arrow;
	int	arrow2;

	arrow = 141;
	arrow2 = 0;
	while (arrow2 < 6)
	{
		sprite[arrow] = new_exa[arrow2];
		arrow++;
		arrow2++;
	}
}

char	*p_make_hex(int num, int arrow)
{
	char	hex[2];
	int		base;
	int		count;

	count = 0;
	base = 1;
	while (++count && (num / base) >= 16)
		base *= 16;
	while (count-- >= 1)
	{
		if ((num / base) <= 9)
		{
			hex[arrow] = ((num / base) + 48);
			arrow++;
		}
		else
		{
			hex[arrow] = ((num / base) + 55);
			arrow++;
		}
		num %= base;
		base /= 16;
	}
	return (ft_strdup(hex));
}

void	p_change_sprite(char *sprite, int sprite_fd)
{
	char		*hexcolor;
	char		*random_hex;
	int			random_color;
	int			n;

	hexcolor = malloc(sizeof(char) * 7);
	hexcolor[6] = '\0';
	ft_bzero(hexcolor, 7);
	n = 3;
	while (n < 8)
	{
		srand(time(NULL) + rand());
		random_color = ((rand() % 230) + 16);
		random_hex = p_make_hex(random_color, 0);
		ft_strlcat(hexcolor, random_hex, n);
		free(random_hex);
		n += 2;
	}
	p_change_hexa(sprite, hexcolor);
	free(hexcolor);
	pwrite(sprite_fd, sprite, 4283, 0);
}

void	p_bonus_animation(t_atributes *data)
{
	if (!data->mlx.p_sprite)
	{
		data->mlx.p_sprite = malloc(sizeof(char) * 4283);
		data->mlx.p_sprite[4282] = '\0';
		data->mlx.p_sprite_fd = open("textures/P.xpm", O_RDWR | 0644);
		read(data->mlx.p_sprite_fd, data->mlx.p_sprite, 4282);
	}
	p_change_sprite(data->mlx.p_sprite, data->mlx.p_sprite_fd);
}
