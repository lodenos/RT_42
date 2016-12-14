/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sepia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodenos <glodenos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/12 01:08:12 by glodenos          #+#    #+#             */
/*   Updated: 2016/12/13 17:03:56 by glodenos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_RT.h"

/*
 *	0x704214FF
 */

void	sepia(unsigned int *img, size_t resolution)
{
	filtered_black_white(img, resolution);
	filtered_rgb(0xAE8964FF, img, resolution);
}
