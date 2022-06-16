/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_cub.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjose-ye <mjose-ye@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 20:36:58 by mjose-ye          #+#    #+#             */
/*   Updated: 2022/06/16 12:18:27 by mjose-ye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	free_vector(t_data *data)
{
	int	i;

	i = 0;
	if(!data->map.map)
		return ;
	while (data->map.map[i])
	{
		free(data->map.map[i]);
		i++;
	}
	free(data->map.map);
	data->map.map = NULL;
}

void	free_images(t_data *data)
{
	if(data->n_img)
	{
		mlx_destroy_image(data->mlx, data->n_img->img);
		free(data->n_img);
	}
	if(data->s_img)
	{
		mlx_destroy_image(data->mlx, data->s_img->img);
		free(data->s_img);
	}
	if(data->w_img)
	{
		mlx_destroy_image(data->mlx, data->w_img->img);
		free(data->w_img);
	}
	if(data->e_img)
	{
		mlx_destroy_image(data->mlx, data->e_img->img);
		free(data->e_img);
	}
	if(data->n_tex)
		free(data->n_tex);
	if(data->s_tex)
		free(data->s_tex);
	if(data->w_tex)
		free(data->w_tex);
	if(data->w_tex)
		free(data->e_tex);
	data->n_img = NULL;
	data->s_img = NULL;
	data->w_img = NULL;
	data->e_img = NULL;
	if (data->mlx)
	{
		mlx_clear_window(data->mlx, data->win);
		mlx_loop_end(data->mlx);
		mlx_destroy_window(data->mlx, data->win);
		mlx_destroy_display(data->mlx);
		free(data->mlx);
	}
}