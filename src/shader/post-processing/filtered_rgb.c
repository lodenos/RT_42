/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filtered_rgb.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodenos <glodenos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 20:39:20 by glodenos          #+#    #+#             */
/*   Updated: 2016/12/09 15:19:59 by glodenos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_RT.h"

void    filtered_rgb(unsigned int filter, unsigned int *img, size_t resolution)
{
	unsigned int   i;

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
