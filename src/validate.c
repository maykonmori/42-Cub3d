/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkenji-s <rkenji-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 02:47:13 by rkenji-s          #+#    #+#             */
/*   Updated: 2022/06/23 02:47:44 by rkenji-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	validate_map(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (data->map.map[y])
	{
		x = 0;
		while (data->map.map[y][x])
		{
			if (!(ft_strchr("01NESW ", data->map.map[y][x])))
			{
				free_split(data->map.map);
				error(data, "Invalid char");
			}
			validate_nesw(x, y, data);
			x++;
		}
		y++;
	}
	verify_wall(data);
	error_player(data);
}

void	validate_nesw(int x, int y, t_data *data)
{
	if (ft_strchr("NESW", data->map.map[y][x]))
	{
		data->map.cont_player++;
		data->py = (y * 64) + 32;
		data->px = (x * 64) + 32;
		if (data->map.map[y][x] == 'N')
			data->pa = PI / 2;
		if (data->map.map[y][x] == 'E')
			data->pa = 0;
		if (data->map.map[y][x] == 'S')
			data->pa = (3 * PI) / 2;
		if (data->map.map[y][x] == 'W')
			data->pa = PI;
	}
}

int	validate_cub(char *s, char *ext)
{
	int	len_s;
	int	len_ext;

	len_s = ft_strlen(s);
	len_ext = ft_strlen(ext);
	while (len_ext > 0)
	{
		if (ext[len_ext] == s[len_s])
		{
			len_ext--;
			len_s --;
		}
		else
			return (0);
	}
	return (1);
}
