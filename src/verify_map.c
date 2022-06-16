/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjose-ye <mjose-ye@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 13:00:48 by mjose-ye          #+#    #+#             */
/*   Updated: 2022/06/16 13:04:19 by mjose-ye         ###   ########.fr       */
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
				free_vector(data);
				error("Invalid char", EXIT_FAILURE);
			}
			validate_cep(x, y, data);
			x++;
		}
		y++;
	}
	verify_wall(data);
	error_player(data);
}

void	get_map(t_data *data)
{
	int	n;
	char *temp;

	n = 0;
	temp = data->map.temp;
	if (data->map.map_start == 0)
	{
		printf("get_map01");
		exit (1);
	}
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
		if (check_map_chars(data->map.map[n]) == 0 || data->map.map[n][0] == '\n')
		{
			printf("get_map02");
			exit_click(data);
			exit (1);
		}
		n++;
	}
}

void check_info(t_data *data)
{
	if(data->n_tex == NULL)
		exit_click(data);
	if(data->s_tex == NULL)
		exit_click(data);
	if(data->w_tex == NULL)
		exit_click(data);
	if(data->e_tex == NULL)
		exit_click(data);
	if(data->s_tex == NULL)
		exit_click(data);
	if(data->f_color == 0)
		exit_click(data);
	if(data->c_color == 0)
		exit_click(data);
}

void	verify_map(char **argv, t_data *data)
{
	int	fd;

	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		error("file was not opened", EXIT_FAILURE);
	if (validate_cub(argv[1], ".cub") == 0)
		error("map is not .cub", EXIT_FAILURE);
	data->map.cont_player = 0;
	data->map.temp = ft_strdup("");
	data->map.count_line = 0;
	data->map.map_start = 0;
	data->n_tex = NULL;
	data->s_tex = NULL;
	data->w_tex = NULL;
	data->e_tex = NULL;
	data->c_color = 0;
	data->f_color = 0;
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
	check_info(data);
	get_map(data);
	validate_map(data);
	close(fd);
}
