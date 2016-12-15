/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodenos <glodenos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/23 00:06:30 by glodenos          #+#    #+#             */
/*   Updated: 2016/12/15 13:30:12 by opettex-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_rt.h"

inline void	camera(register t_cam cam, t_ray *ray, register float x,
	register float y)
{
	float   t;

    cam.fov = 1.0f;
    ray->pos = cam.pos;
    ray->dir.x = ((float)x * cam.fov - (float)cam.w / 2.0f) / (float)cam.h;
    ray->dir.y = ((float)y * cam.fov - (float)cam.h / 2.0f) / (float)cam.h;
    ray->dir.z = 1.0f;
    ray->dir = normalize(ray->dir);
    t = ray->dir.y;
    ray->dir.y = t * cosf(cam.rotate.x) - ray->dir.z * sinf(cam.rotate.x);
    ray->dir.z = t * sinf(cam.rotate.x) + ray->dir.z * cosf(cam.rotate.x);
    t = ray->dir.z;
    ray->dir.z = t * cosf(cam.rotate.y) - ray->dir.x * sinf(cam.rotate.y);
    ray->dir.x = t * sinf(cam.rotate.y) + ray->dir.x * cosf(cam.rotate.y);
    t = ray->dir.x;
    ray->dir.x = t * cosf(cam.rotate.z) - ray->dir.y * sinf(cam.rotate.z);
    ray->dir.y = t * sinf(cam.rotate.z) + ray->dir.y * cosf(cam.rotate.z);
}
