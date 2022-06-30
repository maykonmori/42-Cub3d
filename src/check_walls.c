/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_walls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkenji-s <rkenji-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 03:31:55 by rkenji-s          #+#    #+#             */
/*   Updated: 2022/07/01 01:23:32 by rkenji-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	check_diagonal_2(t_data *data, int y, int x)
{
	int	temp_x;
	int	temp_y;

	temp_x = x;
	temp_y = y;
	while (x >= 0 && y < data->map.y_size && data->map.map[y][x] != ' ')
	{
		if (data->map.map[y][x] == '1')
			break ;
		x--;
		y++;
	}
	if (x < 0 || (data->map.map[y] && data->map.map[y][x] != '1'))
		error(data, "Error\nMap not surrounded by walls\n");
	while (temp_y >= 0 && temp_x < data->map.x_size \
	&& data->map.map[temp_y][temp_x] != ' ')
	{
		if (data->map.map[temp_y][temp_x] == '1')
			return ;
		temp_y--;
		temp_x++;
	}
	error(data, "Error\nMap not surrounded by walls\n");
}

void	check_diagonal_1(t_data *data, int y, int x)
{
	int	temp_x;
	int	temp_y;

	temp_x = x;
	temp_y = y;
	while (x < data->map.x_size && y < data->map.y_size \
	&& data->map.map[y][x] != ' ')
	{
		if (data->map.map[y][x] == '1')
			break ;
		x++;
		y++;
	}
	if (data->map.map[y] && data->map.map[y][x] != '1')
		error(data, "Error\nMap not surrounded by walls\n");
	while (temp_y >= 0 && temp_x >= 0 && data->map.map[temp_y][temp_x] != ' ')
	{
		if (data->map.map[temp_y][temp_x] == '1')
			return ;
		temp_y--;
		temp_x--;
	}
	error(data, "Error\nMap not surrounded by walls\n");
}

void	check_horizontal(t_data *data, int y, int x)
{
	int	temp_x;
	int	temp_y;

	temp_x = x;
	temp_y = y;
	while (x < data->map.x_size && data->map.map[y][x] != ' ')
	{
		if (data->map.map[y][x] == '1')
			break ;
		x++;
	}
	if (data->map.map[y][x] != '1')
		error(data, "Error\nMap not surrounded by walls\n");
	while (temp_x >= 0 && data->map.map[temp_y][temp_x] != ' ')
	{
		if (data->map.map[temp_y][temp_x] == '1')
			return ;
		temp_x--;
	}
	error(data, "Error\nMap not surrounded by walls\n");
}

void	check_vertical(t_data *data, int y, int x)
{
	int	temp_x;
	int	temp_y;

	temp_x = x;
	temp_y = y;
	while (y >= 0 && data->map.map[y] && data->map.map[y][x] != ' ')
	{
		if (data->map.map[y][x] == '1')
			break ;
		y--;
	}
	if (y < 0 || (data->map.map[y] && data->map.map[y][x] != '1'))
		error(data, "Error\nMap not surrounded by walls\n");
	while (temp_y < data->map.y_size && data->map.map[temp_y][temp_x] != ' ')
	{
		if (data->map.map[temp_y][temp_x] == '1')
			return ;
		temp_y++;
	}
	error(data, "Error\nMap not surrounded by walls\n");
}

void	check_walls(t_data *data)
{
	int	y;
	int	x;

	y = -1;
	while (data->map.map[++y])
	{
		x = -1;
		while (data->map.map[y][++x])
		{
			if (data->map.map[y][x] == '0' || data->map.map[y][x] == 'N' || \
			data->map.map[y][x] == 'S' || data->map.map[y][x] == 'W' \
			|| data->map.map[y][x] == 'E')
			{
				check_vertical(data, y, x);
				check_horizontal(data, y, x);
				check_diagonal_1(data, y, x);
				check_diagonal_2(data, y, x);
			}
		}
	}
}
