/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodenos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/23 00:06:30 by glodenos          #+#    #+#             */
/*   Updated: 2016/09/23 03:49:04 by glodenos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_RT.h"

inline void camera(register t_cam cam, t_ray *ray, register size_t x,
        register size_t y)
{
    /* TODO refaire la camera   */
    (void)cam;

    ray->a.x = 0;
    ray->a.y = 0;
    ray->a.z = 0;
    ray->b.x = (int)x - (WIDTH / 2);
    ray->b.y = (int)y - (HEIGHT / 2);
    ray->b.z = 3500;
}
