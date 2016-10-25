/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodenos <glodenos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2100/01/01 00:00:00 by glodenos          #+#    #+#             */
/*   Updated: 2016/01/06 00:42:12 by glodenos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dest, char const *src, size_t count)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (dest[i] && i < count)
		i++;
	j = i;
	while (src[i - j] && i < count - 1)
	{
		dest[i] = src[i - j];
		i++;
	}
	if (j < count)
		dest[i] = '\0';
	return (j + ft_strlen(src));
}
