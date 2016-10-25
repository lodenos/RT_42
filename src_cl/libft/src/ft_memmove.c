/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodenos <glodenos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2100/01/01 00:00:00 by glodenos          #+#    #+#             */
/*   Updated: 2100/01/01 00:00:00 by glodenos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, void const *src, size_t n)
{
	char	*tmp_dest;
	char	*tmp_src;

	tmp_dest = (char *)dest;
	tmp_src = (char *)src;
	if (tmp_src < tmp_dest)
	{
		tmp_dest = tmp_dest + n - 1;
		tmp_src = tmp_src + n - 1;
		while (n-- > 0)
			*tmp_dest-- = *tmp_src--;
	}
	else
		while (n-- > 0)
			*tmp_dest++ = *tmp_src++;
	return (dest);
}
