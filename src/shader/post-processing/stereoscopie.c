/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stereoscopie.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrandria <nrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 09:50:11 by nrandria          #+#    #+#             */
/*   Updated: 2016/12/14 14:05:28 by anespoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_RT.h"

unsigned int	*stereoscopie(unsigned int *img_l,
							unsigned int *img_r, size_t resolution)
{
	unsigned int	*left;
	unsigned int	*right;
	unsigned int	*img;
	cl_float3		a;

	if (!(left = (unsigned int *)ft_memalloc(sizeof(unsigned int) *
					resolution)))
		ft_putstr_err("ERROR malloc", 1);
	if (!(right = (unsigned int *)ft_memalloc(sizeof(unsigned int) *
					resolution)))
		ft_putstr_err("ERROR malloc", 1);
	a.x = 1;
	a.y = 10;
	a.z = 0;
	ft_memcpy((void *)left, (void *)img_l, resolution * 4);
	ft_memcpy((void *)right, (void *)img_r, resolution * 4);
	filtered_rgb(0xFF0000FF, left, resolution);
	filtered_rgb(0x00FFFFFF, right, resolution);
	if (!(img = (unsigned int *)ft_memalloc(sizeof(unsigned int) * resolution)))
		ft_putstr_err("ERROR malloc", 1);
	while (a.z < resolution)
		img[(int)a.z++] = left[(int)a.x++] + right[(int)a.y++];
	free(left);
	free(right);
	return (img);
}
