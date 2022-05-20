/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjose-ye <mjose-ye@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 13:00:48 by mjose-ye          #+#    #+#             */
/*   Updated: 2022/05/20 13:50:08 by mjose-ye         ###   ########.fr       */
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

void	verify_map(char *argv, t_data *data)
{
	int	fd;

	fd = open(argv, O_RDONLY);
	if (fd < 0)
		error("file was not opened", EXIT_FAILURE);
	if (validate_ber(argv, ".ber") == 0)
		error("map is not .ber", EXIT_FAILURE);
	data->map.temp = ft_strdup("");
	data->map.count_line = 0;
	while (1)
	{
		data->map.line = get_next_line(fd);
		if (data->map.line == NULL)
			break ;
		data->map.temp = ft_strjoin_free(data->map.temp, data->map.line);
		free(data->map.line);
		data->map.count_line++;
	}
	validate_map(data);
	close(fd);
}