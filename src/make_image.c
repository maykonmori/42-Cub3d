/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkenji-s <rkenji-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 16:04:14 by mjose-ye          #+#    #+#             */
/*   Updated: 2022/05/25 01:57:56 by rkenji-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	make_vertical_line(t_data *data, int distance, int color)
{
	int	lineH;
	int	x;
	int	lineO;
	int	y_max;

	lineH = (TILE_SIZE * 512) / distance;
	if (lineH > 512)
		lineH = 512;
	lineO = 256 - lineH / 2;
	y_max = lineO + lineH;
	while (lineO <= y_max)
	{
		x = (data->ray_num * 8) + 512;
		while (x < (data->ray_num * 8) + 520)
			my_img_pixel_put(data, x++, lineO, color);
		lineO++;
	}
}

void	make_square(t_data *data, int x, int y, int color)
{
	int	x_max;
	int	y_max;

	x_max = x + TILE_SIZE;
	y_max = y + TILE_SIZE;
	y -= 1;
	while (++y <= y_max)
	{
		x = x_max - 65;
		while (++x <= x_max)
			my_img_pixel_put(data, x, y, color);
	}
}

void	make_image(t_data *data)
{
	int		x;
	int		y;
	double	angle;

	data->img = mlx_new_image(data->mlx, 1024, 1024);
	data->img_addr = mlx_get_data_addr(data->img, &data->img_bits_per_pixel,
			&data->img_line_length, &data->img_endian);
	y = -1;
	while (data->map.map[++y])
	{
		x = -1;
		while (data->map.map[y][++x])
		{
			if (data->map.map[y][x] == '1')
				make_square(data, x * TILE_SIZE, y * TILE_SIZE, 0xFF0000);
			else if (data->map.map[y][x] == '0')
				make_square(data, x * TILE_SIZE, y * TILE_SIZE, 0x808080);
			else if (data->map.map[y][x] == 'N')
				make_square(data, x * TILE_SIZE, y * TILE_SIZE, 0x808080);
		}
	}
	draw_player(data, round(data->px), round(data->py));
	angle = data->pa;
	data->pa += 0.0174533 * 30;
	while (data->ray_num < 60)
	{
		draw_line_from_player(data, round(data->px) + roundf(100 * cos(data->pa)), round(data->py) - roundf(100 * sin(data->pa)));
		data->pa -= 0.0174533;
		data->ray_num++;
	}
	data->ray_num = 0;
	data->pa = angle;
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	mlx_destroy_image(data->mlx, data->img);
}

void	draw_line_from_player(t_data *data, double x, double y)
{
	double	ix;
	double	iy;
	double	dx;
	double	dy;
	int		axis;

	dx = abs((int)x - (int)round(data->px));
	dy = abs((int)y - (int)round(data->py));
	ix = 0;
	iy = 0;
	while (data->map.map[((int)round(data->py) + (int)iy) / TILE_SIZE][((int)round(data->px) + (int)ix) / TILE_SIZE] != '1')
	{
		if ((0.5 + abs((int)ix)) / dx < (0.5 + abs((int)iy)) / dy)
		{
			if (round(data->px) < x)
				ix++;
			else
				ix--;
			axis ='x';
		}
		else
		{
			if (round(data->py) < y)
				iy++;
			else
				iy--;
			axis = 'y';
		}
		my_img_pixel_put(data, round(data->px) + (int)ix, round(data->py) + (int)iy, 0xFFFF00);
	}
	if (axis == 'x')
		make_vertical_line(data, round(sqrt((iy * iy) + (ix * ix))), 0x0000FF);
	else
		make_vertical_line(data, round(sqrt((iy * iy) + (ix * ix))), 0x0000D1);
}
