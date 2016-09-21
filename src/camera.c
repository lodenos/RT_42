/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodenos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/16 14:50:34 by glodenos          #+#    #+#             */
/*   Updated: 2016/09/22 01:26:07 by glodenos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_RT.h"

void	camera(t_cam *cam, t_ray *ray, int x, int y)
{
    t_vec3  vpul;
    t_vec3  vect_up;
    t_vec3  vect_right;
    t_vec3  uu;
    t_vec3  vv;
    float   x_indent;
    float   y_indent;

    vect_up    = (t_vec3){0, 1, 0};
    vect_right = (t_vec3){1, 0, 0};

    uu = vector_mult_x(vect_up   , (0.50 / 2.0));
    vv = vector_mult_x(vect_right, (0.35 / 2.0));

    vpul = vector_add(cam->dir, uu);
    vpul = vector_sub(vpul, vv);
    vpul = vector_add(cam->pos, vpul); 

    x_indent = 0.35 / (double)cam->h;
    y_indent = 0.50 / (double)cam->w;

    vv = vector_mult_x(vect_right, (x * x_indent));
    uu = vector_mult_x(vect_up   , (y * y_indent));

    ray->b = vector_add(vpul, vv);
    ray->b = vector_sub(ray->b, uu);

    ray->b = vector_normalize(ray->b);
    ray->a = cam->pos;
}
