/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_tex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjose-ye <mjose-ye@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 02:55:17 by rkenji-s          #+#    #+#             */
/*   Updated: 2022/06/18 10:53:07 by mjose-ye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

char	*add_tex_location(char *line, char *tex, t_data *data)
{
	char	*ret;
	// char	*temp;

	if (tex != NULL)
	{
		printf ("Error\nInvalid texture");
		exit_click(data);
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
			return (-1);
		n++;
	}
	n = ft_atoi(line);
	if (n > 255 || n < 0)
	{
		printf("Error\n Invalid RGB\n");
		exit_click(data);
	}
	return (n);
}

int	get_rgb(t_data *data, char *line, int color)
{
	char	**split;
	char	*temp;
	int		r;
	int		g;
	int		b;
	int		i;

	i = 0;
	temp = line;
	line++;
	if (color != 0)
	{
		printf("Error\nRepeated color\n");
		exit_click(data);
	}
	while (*line == ' ')
		line++;
	split = ft_split(line, ',');
	i = matriz_len(split);
	if(i != 3)
	{
		printf("Error\n Invalid RGB\n");
		free_split(split);
		exit_click(data);
	}
	line = temp;
	r = check_colors(data, split[0]);
	g = check_colors(data, split[1]);
	b = check_colors(data, split[2]);
	if (split[3] != NULL)
	{
		printf ("get_rgb 02");
		exit (1);
	}
	free_split(split);
	split = NULL;
	if (r == -1 || g == -1 || b == -1)
	{
		printf("Error\n Invalid RGB\n");
		exit_click(data);
	}
	return ((r * 65536) + (g * 256) + b);
}

void	check_line(t_data *data, char *line)
{
	if (ft_strncmp("NO ", line, 3) == 0)
		data->n_tex = add_tex_location(line, data->n_tex, data);
	if (ft_strncmp("SO ", line, 3) == 0)
		data->s_tex = add_tex_location(line, data->s_tex, data);
	if (ft_strncmp("WE ", line, 3) == 0)
		data->w_tex = add_tex_location(line, data->w_tex, data);
	if (ft_strncmp("EA ", line, 3) == 0)
		data->e_tex = add_tex_location(line, data->e_tex, data);
	if (ft_strncmp("F ", line, 2) == 0)
		data->f_color = get_rgb(data, line, data->f_color);
	if (ft_strncmp("C ", line, 2) == 0)
		data->c_color = get_rgb(data, line, data->c_color);
	if (check_map_chars(line) == 1 && data->map.map_start == 0)
		data->map.map_start = data->map.count_line;
}