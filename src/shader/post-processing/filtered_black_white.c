/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filtered_black_white.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodenos <glodenos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 20:40:27 by glodenos          #+#    #+#             */
/*   Updated: 2016/12/15 13:33:13 by opettex-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_rt.h"

void				filtered_black_white(unsigned int *img, size_t resolution)
{
	unsigned int	i;
	unsigned int	tmp;
	unsigned char	red;
	unsigned char	green;
	unsigned char	blue;

	i = 0;
	while (i < resolution)
	{
		tmp = 0;
		red = (unsigned char)(img[i] >> 24);
		green = (unsigned char)(img[i] >> 16);
		blue = (unsigned char)(img[i] >> 8);
		if (tmp < red)
			tmp = red;
		if (tmp < green)
			tmp = green;
		if (tmp < blue)
			tmp = blue;
		img[i] = tmp << 24 | tmp << 16 | tmp << 8 | 0xFF;
		++i;
	}
}
