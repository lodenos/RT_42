/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodenos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/16 14:50:34 by glodenos          #+#    #+#             */
/*   Updated: 2016/09/19 03:52:29 by glodenos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_RT.h"

void	camera(t_cam *cam, t_ray *ray, int x, int y)
{
	(void)cam;
 
    ray->max = 0;
    ray->a.x = cam->w / 2;
    ray->a.y = cam->h / 2;
    ray->a.z = 5000;
    ray->b.x = x - cam->w / 2;
    ray->b.y = y - cam->h / 2;
    ray->b.z = -800;
}
