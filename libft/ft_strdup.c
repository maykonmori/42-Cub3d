/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjose-ye <coder@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/29 16:36:59 by mjose-ye          #+#    #+#             */
/*   Updated: 2021/12/08 18:16:47 by mjose-ye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char *s)
{
	char	*new;
	char	*res;
	ssize_t	i;

	i = 0;
	while ((s[i] != '\0'))
		i++;
	res = malloc(i + 1);
	new = res;
	while (*s)
		*new++ = *s++;
	*new = 0;
	return (res);
}
