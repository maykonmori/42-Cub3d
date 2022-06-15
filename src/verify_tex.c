/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_tex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjose-ye <mjose-ye@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 02:55:17 by rkenji-s          #+#    #+#             */
/*   Updated: 2022/06/15 10:47:44 by mjose-ye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

char	*add_tex_location(char *line, char *tex)
{
	char	*ret;
	// char	*temp;

	if (tex != NULL)
	{
		printf ("tex error");
		exit(1);
	}
	ret = line + 3;
	while (*ret == ' ')
		ret++;
	// temp = ft_strdup(ret);
	ret = ft_strtrim(ret, "\n");
	// free (temp);
	return (ret);
}

int	check_colors(t_data *data, char *line)
{
	int	n;

	n = 0;
	(void)data;
	while (line[n] == ' ')
		n++;
	while (line[n] != '\0')
	{
		if (ft_isdigit(line[n]) == 0 && line[n] != '\n')
		{
			printf ("color error: %i", line[n]);
			exit (1);
		}
		n++;
	}
	n = ft_atoi(line);
	if (n > 255 || n < 0)
		exit (1);
	return (n);
}

int	get_rgb(t_data *data, char *line, int color)
{
	char	**split;
	int		r;
	int		g;
	int		b;

	if (color != 0)
	{
		printf ("get_rgb error");
		exit (1);
	}
	while (*line == ' ')
		line++;
	split = ft_split(line, ',');
	r = check_colors(data, split[0]);
	g = check_colors(data, split[1]);
	b = check_colors(data, split[2]);
	if (split[3] != NULL)
		exit (1);
	return ((r * 65536) + (g * 256) + b);
}

void	check_line(t_data *data, char *line)
{
	if (ft_strncmp("NO ", line, 3) == 0)
		data->n_tex = add_tex_location(line, data->n_tex);
	if (ft_strncmp("SO ", line, 3) == 0)
		data->s_tex = add_tex_location(line, data->s_tex);
	if (ft_strncmp("WE ", line, 3) == 0)
		data->w_tex = add_tex_location(line, data->w_tex);
	if (ft_strncmp("EA ", line, 3) == 0)
		data->e_tex = add_tex_location(line, data->e_tex);
	if (ft_strncmp("F ", line, 2) == 0)
		data->f_color = get_rgb(data, line + 1, data->f_color);
	if (ft_strncmp("C ", line, 2) == 0)
		data->c_color = get_rgb(data, line + 1, data->c_color);
	if (check_map_chars(line) == 1 && data->map.map_start == 0)
		data->map.map_start = data->map.count_line;
}