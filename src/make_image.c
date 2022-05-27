/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkenji-s <rkenji-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 16:04:14 by mjose-ye          #+#    #+#             */
/*   Updated: 2022/05/27 03:27:47 by rkenji-s         ###   ########.fr       */
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
	data->ra = data->pa + (PI / 180 * 32);
	while (data->ray_num < 64)
	{
		draw_line_from_player(data, cos(data->ra), sin(data->ra));
		data->ra -= PI / 180;
		data->ray_num++;
	}
	data->ray_num = 0;
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	mlx_destroy_image(data->mlx, data->img);
}

void	draw_line_from_player(t_data *data, double x_angle, double y_angle)
{
	double		ix;
	double		iy;
	float		ca;
	float		dist;

	ix = 0;
	iy = 0;
	while (data->map.map[(int)round(data->py + iy) / TILE_SIZE][(int)round(data->px + ix) / TILE_SIZE] != '1')
	{
		ix += x_angle;
		iy -= y_angle;
		my_img_pixel_put(data, round(data->px + ix), round(data->py + iy), 0xFFFF00);
	}
	ca = data->pa - data->ra;
	if (ca < 2 * PI)
		ca += 2 * PI;
	if (ca > 2 * PI)
		ca -= 2 * PI;
	dist = sqrt((iy * iy) + (ix * ix)) * cos(ca);
	if (data->map.map[(int)round(data->py + iy) / TILE_SIZE][(int)round(data->px + ix - x_angle) / TILE_SIZE] != '1')
		make_vertical_line(data, round(dist), 0xFF0000);
	else
		make_vertical_line(data, round(dist), 0xCC0000);
}
