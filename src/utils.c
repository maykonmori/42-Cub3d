/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjose-ye <mjose-ye@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 02:55:47 by rkenji-s          #+#    #+#             */
/*   Updated: 2022/06/17 13:17:37 by mjose-ye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

char	*ft_strjoin_free(char *s1, char const *s2)
{
	char	*nstring;
	size_t	i;
	size_t	a;

	nstring = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	i = 0;
	a = 0;
	if (nstring == 0)
		return (0);
	while (s1[i] != '\0')
	{
		nstring[i] = s1[i];
		i++;
	}
	while (s2[a] != '\0')
	{
		nstring[i + a] = s2[a];
		a++;
	}
	nstring[i + a] = '\0';
	free(s1);
	s1 = NULL;
	return (nstring);
}

int	check_map_chars(char *line)
{
	int		n;

	n = 0;
	if (line[0] == '\n')
		return (0);
	while (line[n] != '\0')
	{
		if (!(ft_strchr("01NESW \n", line[n])))
			return (0);
		n++;
	}
	return (1);
}

int	matriz_len(char **split)
{
	int	i;

	i = 0;
	if (!split)
		return (0);
	while (split[i])
		i++;
	return (i);
}
