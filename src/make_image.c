/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkenji-s <rkenji-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 16:04:14 by mjose-ye          #+#    #+#             */
/*   Updated: 2022/05/23 23:09:50 by rkenji-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	make_square(t_data *data, int x, int y, int color)
{
	int	x_max;
	int	y_max;

	x_max = x + 64;
	y_max = y + 64;
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

	data->img = mlx_new_image(data->mlx, data->map.count_column * 64, data->map.count_line * 64);
	data->img_addr = mlx_get_data_addr(data->img, &data->img_bits_per_pixel,
			&data->img_line_length, &data->img_endian);
	y = -1;
	while (data->map.map[++y])
	{
		x = -1;
		while (data->map.map[y][++x])
		{
			if (data->map.map[y][x] == '1')
				make_square(data, x * 64, y * 64, 0xFF0000);
			else if (data->map.map[y][x] == '0')
				make_square(data, x * 64, y * 64, 0x808080);
			else if (data->map.map[y][x] == 'N')
				make_square(data, x * 64, y * 64, 0x808080);
		}
	}
	
	draw_player(data, data->px, data->py);
	draw_line_from_player(data, data->px + roundf(100 * sin(data->pa)), data->py + roundf(100 * cos(data->pa)));
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}

void	draw_line_from_player(t_data *data, double x, double y)
{
	double	ix;
	double	iy;
	double	dx;
	double	dy;

	dx = abs((int)x - data->px);
	dy = abs((int)y - data->py);
	ix = 0;
	iy = 0;
	while (abs((int)ix) < dx || abs((int)iy) < dy)
	{
		if ((0.5 + abs((int)ix)) / dx < (0.5 + abs((int)iy)) / dy)
		{
			if (data->px < x)
				ix++;
			else
				ix--;
		}
		else
		{
			if (data->py < y)
				iy++;
			else
				iy--;
		}
		my_img_pixel_put(data, data->px + ix, data->py + iy, 0xFFFF00);
	}
}