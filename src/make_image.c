/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkenji-s <rkenji-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 16:04:14 by mjose-ye          #+#    #+#             */
/*   Updated: 2022/06/17 03:19:07 by rkenji-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	make_vertical_line(t_data *data, int distance, double ix, t_img *img)
{
	int	lineH;
	int	x;
	int	lineO;
	int	y_max;
	int	y_ceil;
	float	ty;
	float	ty_step;
	float	ty_off;
	float	tx;

	y_ceil = 0;
	if (distance == 0)
		distance = 1;
	lineH = (TILE_SIZE * 512) / distance;
	ty_step = 64.0 / (float)lineH;
	ty_off = 0;
	if (lineH > 512)
	{
		ty_off = (lineH - 512) / 2.0;
		lineH = 512;
	}
	lineO = 256 - lineH / 2;
	y_max = lineO + lineH;
	tx = (int)(ix / 2.0) % 32;
	if (img == data->s_img)
		tx = 31 - tx;
	ty = ty_off * ty_step;
	while (y_ceil <= lineO)
	{
		x = (data->ray_num * 8);
		while (x < (data->ray_num * 8) + 8)
			my_img_pixel_put(data->game_img, x++, y_ceil, data->c_color);
		y_ceil++;
	}
	while (lineO <= y_max)
	{
		x = (data->ray_num * 8);
		while (x < (data->ray_num * 8) + 8)
			my_img_pixel_put(data->game_img, x++, lineO, my_img_pixel_get(img, (int)tx, (int)ty));
		lineO++;
		ty += ty_step;
	}
	while (y_max <= 512)
	{
		x = (data->ray_num * 8);
		while (x < (data->ray_num * 8) + 8)
			my_img_pixel_put(data->game_img, x++, y_max, data->f_color);
		y_max++;
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
			my_img_pixel_put(data->game_img, x, y, color);
	}
}

void	make_image(t_data *data)
{
	// int		x;
	// int		y;

	data->game_img = malloc (sizeof(t_img));
	data->game_img->img = mlx_new_image(data->mlx, 512, 512);
	data->game_img->img_addr = mlx_get_data_addr(data->game_img->img, &data->game_img->img_bits_per_pixel,
			&data->game_img->img_line_length, &data->game_img->img_endian);
	// y = -1;
	// while (data->map.map[++y])
	// {
	// 	x = -1;
	// 	while (data->map.map[y][++x])
	// 	{
	// 		if (data->map.map[y][x] == '1')
	// 			make_square(data, x * TILE_SIZE, y * TILE_SIZE, 0xFF0000);
	// 		else if (data->map.map[y][x] == '0')
	// 			make_square(data, x * TILE_SIZE, y * TILE_SIZE, 0x808080);
	// 		else if (ft_strchr("NEWS", data->map.map[y][x]))
	// 			make_square(data, x * TILE_SIZE, y * TILE_SIZE, 0x808080);
	// 	}
	// }
	// draw_player(data, round(data->px), round(data->py));
	data->ra = data->pa + (PI / 180 * 32);
	while (data->ray_num < 64)
	{
		raycast(data, data->ra);
		data->ra -= PI / 180;
		data->ray_num++;
	}
	data->ray_num = 0;
	mlx_put_image_to_window(data->mlx, data->win, data->game_img->img, 0, 0);
	mlx_destroy_image(data->mlx, data->game_img->img);
	free(data->game_img);
}

