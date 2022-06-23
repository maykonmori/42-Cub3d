/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkenji-s <rkenji-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 16:00:21 by mjose-ye          #+#    #+#             */
/*   Updated: 2022/06/23 03:09:09 by rkenji-s         ###   ########.fr       */
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
		exit_click(data);
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
		exit_click(data);
	return (0);
}

int	check_collision(t_data *data, double ra)
{
	int	map_x;
	int	map_y;

	get_distance(data, ra);
	map_x = data->px + (30 * data->step_x);
	map_y = data->py + (30 * data->step_y);
	map_x = map_x >> 6;
	map_y = map_y >> 6;
	if (data->map.map[map_y][(int)(data->px) >> 6] == '1' || \
	data->map.map[(int)(data->py) >> 6][map_x] == '1' || \
	data->map.map[map_y][map_x] == '1')
		return (0);
	return (1);
}

void	movement(t_data *data)
{
	if (data->move_up == 1 && check_collision(data, data->pa))
	{
		data->px += 2 * cos(data->pa);
		data->py -= 2 * sin(data->pa);
	}
	if (data->move_down == 1 && check_collision(data, data->pa + PI))
	{
		data->px -= 2 * cos(data->pa);
		data->py += 2 * sin(data->pa);
	}
	if (data->move_right == 1 && check_collision(data, data->pa - PI / 2))
	{
		data->px += 2 * sin(data->pa);
		data->py += 2 * cos(data->pa);
	}
	if (data->move_left == 1 && check_collision(data, data->pa + PI / 2))
	{
		data->px -= 2 * sin(data->pa);
		data->py -= 2 * cos(data->pa);
	}
}

int	ft_run(t_data *data)
{
	movement(data);
	if (data->turn_left == 1)
		data->pa += PI / 180;
	if (data->turn_right == 1)
		data->pa -= PI / 180;
	if (data->pa > 2 * PI)
		data->pa -= 2 * PI;
	if (data->pa < 0)
		data->pa += 2 * PI;
	make_image(data);
	return (0);
}
