/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filtered_RGB.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodenos <glodenos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/12 01:08:08 by glodenos          #+#    #+#             */
/*   Updated: 2016/10/12 01:33:31 by glodenos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_RT.h"

void    filtered_rgb(unsigned int filter, unsigned int *img, size_t resolution)
{
	int	i;

	i = 0;
	while (i < resolution)
	{	
		img[i] = (unsigned int)((unsigned int)(unsigned char)(img[i] >> 24) *
				(unsigned int)(unsigned char)(filter >> 24) / 255) << 24 |
				(unsigned int)((unsigned int)(unsigned char)(img[i] >> 16) *
				(unsigned int)(unsigned char)(filter >> 16) / 255) << 16 |
				(unsigned int)((unsigned int)(unsigned char)(img[i] >> 8) *
				(unsigned int)(unsigned char)(filter >> 8) / 255) << 8 | 0xFF;
		++i;
	}
}

void	filtered_b_w(unsigned int *img, size_t resolution)
{
	int i;
	unsigned int tmp;
	unsigned char r;
	unsigned char g;
	unsigned char b;

	i = 0;
	tmp = 0;
	
	while (i < resolution)
	{
		tmp = 0;
		r = (unsigned char)(img[i] >> 24);
		g = (unsigned char)(img[i] >> 16);
		b = (unsigned char)(img[i] >> 8); 
		if (tmp < r)
			tmp = r;
		if (tmp < g)
			tmp = g;
		if (tmp < b)
			tmp = b;
		img[i] = tmp << 24 | tmp << 16 | tmp << 8 | 0xFF; 
		++i;
	}

}