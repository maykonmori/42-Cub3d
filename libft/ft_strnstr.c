/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjose-ye <mjose-ye@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/28 19:31:03 by mjose-ye          #+#    #+#             */
/*   Updated: 2021/09/10 18:58:41 by mjose-ye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *find, size_t len)
{
	size_t	i;

	i = ft_strlen(find);
	if (i == 0)
		return ((char *)str);
	while (*str != 0 && len > 0 && i <= len)
	{
		if (ft_strncmp(str, find, i) == 0)
		{
			return ((char *)str);
		}
		len--;
		str++;
	}
	return (0);
}
