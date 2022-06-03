/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkenji-s <rkenji-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 16:00:21 by mjose-ye          #+#    #+#             */
/*   Updated: 2022/06/03 04:00:44 by rkenji-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "cub3D.h"

int	arrows_down(int keycode, t_data *data)
{
	if (keycode == 97)
		data->move_left = 1;
	if (keycode == 100)
		data->move_right = 1;
	if (keycode == 115)
		data->move_down = 1;
	if (keycode == 119)
		data->move_up = 1;
	if (keycode == 65361)
		data->turn_left = 1;
	if (keycode == 65363)
		data->turn_right = 1;
	if (keycode == 65307)
		exit_click();
	return (0);
}

int	arrows_up(int keycode, t_data *data)
{
	if (keycode == 97)
		data->move_left = 0;
	if (keycode == 100)
		data->move_right = 0;
	if (keycode == 115)
		data->move_down = 0;
	if (keycode == 119)
		data->move_up = 0;
	if (keycode == 65361)
		data->turn_left = 0;
	if (keycode == 65363)
		data->turn_right = 0;
	if (keycode == 65307)
		exit_click();
	return (0);
}

int	ft_run(t_data *data)
{
	int	x_check;
	int	y_check;

	x_check = 1;
	y_check = 1;
	if (cos(data->pa) < 0)
		x_check = -1;
	if (sin(data->pa) < 0)
		y_check = -1;
	if (data->move_up == 1 && data->map.map[((int)round(data->py - (y_check * 10))) / 64][((int)round(data->px + (x_check * 10)) / 64)] != '1')
	{
		data->px += 3 * cos(data->pa);
		data->py -= 3 * sin(data->pa);
	}
	if (data->move_down == 1 && data->map.map[((int)round(data->py + (y_check * 10))) / 64][((int)round(data->px - (x_check * 10)) / 64)] != '1')
	{
		data->px -= 3 * cos(data->pa);
		data->py += 3 * sin(data->pa);
	}
	if (data->move_right == 1 && data->map.map[((int)round(data->py + (x_check * 10))) / 64][((int)round(data->px + (y_check * 10)) / 64)] != '1')
	{
		data->px += 3 * sin(data->pa);
		data->py += 3 * cos(data->pa);
	}
	if (data->move_left == 1 && data->map.map[((int)round(data->py - (x_check * 10))) / 64][((int)round(data->px - (y_check * 10)) / 64)] != '1')
	{
		data->px -= 3 * sin(data->pa);
		data->py -= 3 * cos(data->pa);
	}
	if (data->turn_left == 1)
		data->pa += PI / 180 * 2;
	if (data->turn_right == 1)
		data->pa -= PI / 180 * 2;
	if (data->pa >= (PI * 2) || data->pa <= (PI * -2))
		data->pa = 0;
	make_image(data);
	return (0);
}