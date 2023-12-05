/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_checks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xortega <xortega@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 10:30:16 by xortega           #+#    #+#             */
/*   Updated: 2023/12/04 13:43:39 by xortega          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_walls(t_atributes *data)
{
	int	current_tile;

	current_tile = -1;
	while (data->tiles[++current_tile].tipe)
	{
		if (data->tiles[current_tile].x_cord == 0)
			if (data->tiles[current_tile].tipe != '1')
				error_manager("PEOPLE IN THE LEFT WALL");
		if (data->tiles[current_tile].x_cord == (data->wide - 1))
			if (data->tiles[current_tile].tipe != '1')
				error_manager("PEOPLE IN THE RIGTH WALL");
		if (data->tiles[current_tile].y_cord == 0)
			if (data->tiles[current_tile].tipe != '1')
				error_manager("PEOPLE IN THE TOP WALL");
		if (data->tiles[current_tile].y_cord == (data->tall - 1))
			if (data->tiles[current_tile].tipe != '1')
				error_manager("PEOPLE IN THE BOTTOM WALL");
	}
}

void	check_caracters(t_atributes *data)
{
	int	current_tile;

	current_tile = -1;
	while (data->tiles[++current_tile].tipe)
	{
		if ((data->tiles[current_tile].tipe != '1') \
		&& (data->tiles[current_tile].tipe != '0') \
		&& (data->tiles[current_tile].tipe != 'P') \
		&& (data->tiles[current_tile].tipe != 'C') \
		&& (data->tiles[current_tile].tipe != 'E'))
			error_manager("I ONLY KNOW HOW TO READ 1, 0, P, C, E");
	}
}

void	check_doubles(t_atributes *data)
{
	int	current_tile;
	int	player_count;
	int	exit_count;
	int	coin_count;

	player_count = 0;
	exit_count = 0;
	coin_count = 0;
	current_tile = -1;
	while (data->tiles[++current_tile].tipe)
	{
		if (data->tiles[current_tile].tipe == 'P')
			player_count++;
		if (data->tiles[current_tile].tipe == 'C')
			coin_count++;
		if (data->tiles[current_tile].tipe == 'E')
			exit_count++;
	}
	check_doubles_error(player_count, exit_count, coin_count);
}

void	check_fill(t_atributes *data)
{
	int	current_tile;

	current_tile = -1;
	while (data->tiles[++current_tile].tipe)
	{
		if (data->tiles[current_tile].tipe == 'P' \
		|| data->tiles[current_tile].tipe == 'C' \
		|| data->tiles[current_tile].tipe == 'E')
		{
			free(data->tiles);
			error_manager("PLAYER CANT REACH THE EXIT");
		}
	}
	free(data->tiles);
}

void	map_check(t_atributes *data)
{
	t_atributes	cpy;

	check_walls(data);
	check_caracters(data);
	check_doubles(data);
	copy_atributes(data, &cpy);
	fill(&cpy, data->tiles[gptl(data)].x_cord, data->tiles[gptl(data)].y_cord);
	check_fill(&cpy);
}
