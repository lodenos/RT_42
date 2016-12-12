/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stereoscopie.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrandria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 09:50:11 by nrandria          #+#    #+#             */
/*   Updated: 2016/12/12 17:04:43 by nrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_RT.h"

unsigned int	*stereoscopie(unsigned int *img_l,
							unsigned int *img_r, size_t resolution)
{
	unsigned int	*left;
	unsigned int	*right;
	unsigned int	*img;
	int				i;
	int				j;
	int				k;

	if (!(left = (unsigned int *)ft_memalloc(sizeof(unsigned int) *
					resolution)))
		ft_putstr_err("ERROR malloc", 1);
	if (!(right = (unsigned int *)ft_memalloc(sizeof(unsigned int) *
					resolution)))
		ft_putstr_err("ERROR malloc", 1);
	i = 1;
	j = 10;
	k = 0;
	ft_memcpy((void *)left, (void *)img_l, resolution * 4);
	ft_memcpy((void *)right, (void *)img_r, resolution * 4);
	filtered_rgb(0xFF000000, left, resolution);
	filtered_rgb(0x00FFFF00, right, resolution);
	if (!(img = (unsigned int *)ft_memalloc(sizeof(unsigned int) * resolution)))
		ft_putstr_err("ERROR malloc", 1);
	while (k < resolution)
		img[k++] = left[i++] + right[j++];
	free(left);
	free(right);
	return (img);
}
