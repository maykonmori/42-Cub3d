/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjose-ye <mjose-ye@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 13:00:48 by mjose-ye          #+#    #+#             */
/*   Updated: 2022/06/07 13:37:24 by mjose-ye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

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

void	validate_cep(int x, int y, t_data *data)
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
			if (!(ft_strchr("01NESW", data->map.map[y][x])))
			{
				free_vector(data);
				error("Invalid char", EXIT_FAILURE);
			}
			validate_cep(x, y, data);
			x++;
		}
		y++;
	}
	error_wall(data);
	error_player(data);
}

void	count_column(t_data *data)
{
	int	len_line;
	int	temp;
	int	i;

	data->map.count_column = 0;
	if (!data->map.temp)
		return ;
	data->map.map = ft_split(data->map.temp, '\n');
	temp = 0;
	len_line = ft_strlen(data->map.map[0]);
	i = 0;
	while (data->map.map[i] != 0)
	{
		temp = ft_strlen(data->map.map[i]);
		if (len_line != temp)
		{
			free(data->map.temp);
			free_vector(data);
			error("Invalid column size", EXIT_FAILURE);
		}
		i++;
	}
	data->map.count_column = temp;
	free(data->map.temp);
}

// void	get_map(t_data *data)
// {

// }

void	verify_map(char **argv, t_data *data)
{
	int	fd;

	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		error("file was not opened", EXIT_FAILURE);
	if (validate_cub(argv[1], ".cub") == 0)
		error("map is not .cub", EXIT_FAILURE);
	data->map.temp = ft_strdup("");
	data->map.count_line = 0;
	while (1)
	{
		data->map.line = get_next_line(fd);
		if (data->map.line == NULL)
			break ;
		check_line(data, data->map.line);
		data->map.temp = ft_strjoin_free(data->map.temp, data->map.line);
		free(data->map.line);
		data->map.count_line++;
	}
	// get_map(data);
	// count_column(data);
	validate_map(data);
	close(fd);
}
