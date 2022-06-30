/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkenji-s <rkenji-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 16:04:14 by mjose-ye          #+#    #+#             */
/*   Updated: 2022/06/30 02:54:45 by rkenji-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	put_vertical_line(t_data *data, t_img *img)
{
	while (data->rc.y_ceil <= data->rc.line_o)
	{
		data->rc.x = (data->ray_num * 8);
		while (data->rc.x < (data->ray_num * 8) + 8)
			my_img_pixel_put(data->game_img, data->rc.x++, data->rc.y_ceil, \
			data->c_color);
		data->rc.y_ceil++;
	}
	while (data->rc.line_o <= data->rc.y_max)
	{
		data->rc.x = (data->ray_num * 8);
		while (data->rc.x < (data->ray_num * 8) + 8)
			my_img_pixel_put(data->game_img, data->rc.x++, data->rc.line_o, \
			my_img_pixel_get(img, (int)data->rc.tx, (int)data->rc.ty));
		data->rc.line_o++;
		data->rc.ty += data->rc.ty_step;
	}
	while (data->rc.y_max <= 512)
	{
		data->rc.x = (data->ray_num * 8);
		while (data->rc.x < (data->ray_num * 8) + 8)
			my_img_pixel_put(data->game_img, data->rc.x++, data->rc.y_max, \
			data->f_color);
		data->rc.y_max++;
	}
}

void	make_vertical_line(t_data *data, int distance, double ix, t_img *img)
{
	data->rc.y_ceil = 0;
	if (distance == 0)
		distance = 1;
	data->rc.line_h = (TILE_SIZE * 512) / distance;
	data->rc.ty_step = 64.0 / (float)data->rc.line_h;
	data->rc.ty_off = 0;
	if (data->rc.line_h > 512)
	{
		data->rc.ty_off = (data->rc.line_h - 512) / 2.0;
		data->rc.line_h = 512;
	}
	data->rc.line_o = 256 - data->rc.line_h / 2;
	data->rc.y_max = data->rc.line_o + data->rc.line_h;
	data->rc.tx = (int)(ix) % 64;
	if (img == data->s_img || img == data->w_img)
		data->rc.tx = 63 - data->rc.tx;
	data->rc.ty = data->rc.ty_off * data->rc.ty_step;
	put_vertical_line(data, img);
}

void	make_image(t_data *data)
{
	data->game_img = malloc (sizeof(t_img));
	data->game_img->img = mlx_new_image(data->mlx, 512, 512);
	data->game_img->img_addr = mlx_get_data_addr(data->game_img->img, \
	&data->game_img->img_bits_per_pixel, &data->game_img->img_line_length, \
	&data->game_img->img_endian);
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
