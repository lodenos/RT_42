/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_sqrt.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodenos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/28 09:59:18 by glodenos          #+#    #+#             */
/*   Updated: 2016/02/28 10:06:42 by glodenos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				**matrix_sqrt(unsigned int x, unsigned int y)
{
	void			**tmp;
	unsigned int	i;

	i = 0;
	if (!(tmp = (void**)malloc(sizeof(tmp) * y)))
		return (tmp);
	while (i < y)
		tmp[i++] = (void*)ft_memalloc(x);
	return (tmp);
}
