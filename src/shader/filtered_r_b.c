/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filtered_r_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opettex- <opettex-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 10:43:30 by opettex-          #+#    #+#             */
/*   Updated: 2016/11/03 10:43:31 by opettex-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_RT.h"

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
