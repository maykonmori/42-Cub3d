/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkenji-s <rkenji-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 13:00:48 by mjose-ye          #+#    #+#             */
/*   Updated: 2022/06/24 02:47:55 by rkenji-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	verify_wall(t_data *data)
{
	int	size;
	int	n;

	size = 0;
	n = -1;
	while (data->map.map[++n] != NULL)
	{
		if ((int)ft_strlen(data->map.map[n]) > size)
			size = ft_strlen(data->map.map[n]);
	}
	data->map.y_size = n;
	data->map.x_size = size;
	n = -1;
	while (data->map.map[++n] != NULL)
	{
		while ((int)ft_strlen(data->map.map[n]) < size)
			data->map.map[n] = ft_strjoin_free(data->map.map[n], " ");
	}
	check_walls(data);
}

void	get_map(t_data *data)
{
	int		n;
	char	*temp;

	n = 0;
	temp = data->map.temp;
	if (data->map.map_start == 0)
		error(data, "Error\nInvalid map\n");
	while (*(data->map.temp) != '\0' && data->map.map_start > 0)
	{
		if (*(data->map.temp) == '\n')
			data->map.map_start--;
		data->map.temp++;
	}
	data->map.map = ft_split(data->map.temp, '\n');
	free(temp);
	data->map.temp = NULL;
	n = 0;
	while (data->map.map[n] != NULL)
	{
		if (check_map_chars(data->map.map[n]) == 0 || \
		data->map.map[n][0] == '\n')
			error(data, "Error\nInvalid map\n");
		n++;
	}
}

void	check_info(t_data *data)
{
	if (data->n_tex == NULL)
		error(data, "Error\nInvalid TEX\n");
	if (data->s_tex == NULL)
		error(data, "Error\nInvalid TEX\n");
	if (data->w_tex == NULL)
		error(data, "Error\nInvalid TEX\n");
	if (data->e_tex == NULL)
		error(data, "Error\nInvalid TEX\n");
	if (data->s_tex == NULL)
		error(data, "Error\nInvalid TEX\n");
	if (data->f_color == -1)
		error(data, "Error\nInvalid RGB\n");
	if (data->c_color == -1)
		error(data, "Error\nInvalid RGB\n");
}

void	verify_map(char **argv, t_data *data)
{
	int	fd;
	int	n;

	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		error(data, "Error\nfile was not opened\n");
	if (validate_cub(argv[1], ".cub") == 0)
		error(data, "Error\nmap is not .cub");
	init_map(data);
	n = -1;
	while (1)
	{
		data->map.line = get_next_line(fd);
		if (data->map.line == NULL)
			break ;
		data->map.temp = ft_strjoin_free(data->map.temp, data->map.line);
		free(data->map.line);
	}
	data->map.lines = ft_split (data->map.temp, '\n');
	while (data->map.lines[++n] != NULL)
		check_line(data, data->map.lines[n]);
	check_info(data);
	get_map(data);
	validate_map(data);
	close(fd);
}
