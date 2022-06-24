/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_tex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjose-ye <mjose-ye@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 21:51:50 by mjose-ye          #+#    #+#             */
/*   Updated: 2022/06/24 11:30:14 by mjose-ye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	check_rgb_line(t_data *data, char *line, char **split)
{
	int	i;
	int	c;

	i = -1;
	c = 0;
	while (line[++i] != '\0')
	{
		if (line[i] == ',')
			c++;
	}
	if (c != 2)
		error(data, "Error\nInvalid RGB\n");
	if (matriz_len(split) != 3)
	{
		free_split(split);
		error(data, "Error\nInvalid RGB\n");
	}
}

char	*add_tex_location(char *line, char *tex, t_data *data)
{
	char	*ret;
	int		fd;
	char	*buff;
	char	*temp;

	buff = 0;
	if (tex != NULL)
		error(data, "Error\nInvalid texture");
	ret = line + 3;
	temp = ret;
	while (*temp == ' ')
		temp++;
	ret = ft_strtrim(temp, "\n");
	fd = open(ret, O_RDONLY);
	if (fd < 0)
		error_tex(data, buff, ret, fd);
	buff = malloc(sizeof(char) * 9);
	if (read(fd, buff, 9) <= 0)
		error_tex(data, buff, ret, fd);
	if (ft_strncmp(buff, "/* XPM */", 9) != 0)
		error_tex(data, buff, ret, fd);
	free (buff);
	close(fd);
	return (ret);
}

int	check_colors(t_data *data, char *line)
{
	int		n;
	char	*temp;

	n = 0;
	temp = ft_strtrim(line, " ");
	while (temp[n] != '\0')
	{
		if (ft_isdigit(temp[n]) == 0 && temp[n] != '\n')
		{
			free (temp);
			return (-1);
		}
		n++;
	}
	n = ft_atoi(temp);
	free (temp);
	if (n > 255 || n < 0)
		error(data, "Error\nInvalid RGB\n");
	return (n);
}

int	get_rgb(t_data *data, char *line, int color)
{
	char	**split;
	char	*temp;
	int		r;
	int		g;
	int		b;

	temp = line;
	line++;
	if (color != -1)
		error(data, "Error\nRepeated color\n");
	while (*line == ' ')
		line++;
	split = ft_split(line, ',');
	check_rgb_line(data, line, split);
	line = temp;
	r = check_colors(data, split[0]);
	g = check_colors(data, split[1]);
	b = check_colors(data, split[2]);
	free_split(split);
	if (r == -1 || g == -1 || b == -1)
		error(data, "Error\nInvalid RGB\n");
	return ((r * 65536) + (g * 256) + b);
}

void	check_line(t_data *data, char *line)
{
	data->map.count_line++;
	if (ft_strncmp("NO ", line, 3) == 0)
		data->n_tex = add_tex_location(line, data->n_tex, data);
	else if (ft_strncmp("SO ", line, 3) == 0)
		data->s_tex = add_tex_location(line, data->s_tex, data);
	else if (ft_strncmp("WE ", line, 3) == 0)
		data->w_tex = add_tex_location(line, data->w_tex, data);
	else if (ft_strncmp("EA ", line, 3) == 0)
		data->e_tex = add_tex_location(line, data->e_tex, data);
	else if (ft_strncmp("F ", line, 2) == 0)
		data->f_color = get_rgb(data, line, data->f_color);
	else if (ft_strncmp("C ", line, 2) == 0)
		data->c_color = get_rgb(data, line, data->c_color);
	else if (check_map_chars(line) == 1 && data->map.map_start == 0)
		data->map.map_start = data->map.count_line;
	else if (check_map_chars(line) == 0)
		error(data, "Error\nInvalid file\n");
}
