/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkenji-s <rkenji-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 02:43:21 by rkenji-s          #+#    #+#             */
/*   Updated: 2022/06/24 02:47:42 by rkenji-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	init_map(t_data *data)
{
	data->map.temp = ft_strdup("");
	data->map.count_line = 0;
	data->map.map_start = 0;
	data->n_tex = NULL;
	data->s_tex = NULL;
	data->w_tex = NULL;
	data->e_tex = NULL;
	data->c_color = -1;
	data->f_color = -1;
}

void	init_game(t_data *data)
{
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, 512, 512, "Cub3d");
	data->n_img = init_texture(data, data->n_tex);
	data->s_img = init_texture(data, data->s_tex);
	data->w_img = init_texture(data, data->w_tex);
	data->e_img = init_texture(data, data->e_tex);
	data->turn_left = 0;
	data->turn_right = 0;
	data->move_up = 0;
	data->move_down = 0;
	data->move_left = 0;
	data->move_right = 0;
	data->ray_num = 1;
}

t_img	*init_texture(t_data *data, char *file)
{
	int		trash;
	t_img	*ret;

	ret = malloc (sizeof(t_img));
	ret->img = mlx_xpm_file_to_image(data->mlx, file, &trash, &trash);
	ret->img_addr = mlx_get_data_addr(ret->img, &ret->img_bits_per_pixel,
			&ret->img_line_length, &ret->img_endian);
	return (ret);
}
