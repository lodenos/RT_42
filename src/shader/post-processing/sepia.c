/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sepia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodenos <glodenos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/12 01:08:12 by glodenos          #+#    #+#             */
/*   Updated: 2016/12/14 12:45:38 by anespoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_RT.h"

void	sepia(unsigned int *img, size_t resolution)
{
	filtered_black_white(img, resolution);
	filtered_rgb(0xAE8964FF, img, resolution);
}
