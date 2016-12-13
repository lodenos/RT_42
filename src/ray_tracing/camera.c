/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodenos <glodenos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/23 00:06:30 by glodenos          #+#    #+#             */
/*   Updated: 2016/12/13 16:07:09 by anespoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_RT.h"

/* TODO remake FOV*/

inline void camera(register t_cam cam, t_ray *ray, register float x,
        register float y)
{
    float   t;

    cam.fov = 1;
    ray->pos = cam.pos;
    ray->dir.x = (x * cam.fov - cam.w / 2) / cam.h;
    ray->dir.y = (y * cam.fov - cam.h / 2) / cam.h;
    ray->dir.z = 1.0f;
    ray->dir = normalize(ray->dir);
    t = ray->dir.y;
    ray->dir.y = t * cosf(cam.rotate.x) - ray->dir.z * sinf(cam.rotate.x);
    ray->dir.z = t * sinf(cam.rotate.x) + ray->dir.z * cosf(cam.rotate.x);
    t = ray->dir.z;
    ray->dir.z = t * cosf(cam.rotate.y) - ray->dir.x * sinf(cam.rotate.y);
    ray->dir.x = t * sinf(cam.rotate.y) + ray->dir.x * cosf(cam.rotate.y);
}
