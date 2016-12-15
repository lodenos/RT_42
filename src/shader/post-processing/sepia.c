/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sepia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodenos <glodenos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/12 01:08:12 by glodenos          #+#    #+#             */
/*   Updated: 2016/12/15 13:33:42 by opettex-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_rt.h"

void	sepia(unsigned int *img, size_t resolution)
{
	filtered_black_white(img, resolution);
	filtered_rgb(0xAE8964FF, img, resolution);
}
