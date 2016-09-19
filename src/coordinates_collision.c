/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coordinates_collision.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodenos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/17 07:23:45 by glodenos          #+#    #+#             */
/*   Updated: 2016/08/22 20:02:28 by glodenos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_RT.h"

void    coordinates_collision(t_obj *obj, t_ray ray)
{
    obj->norm.x = ray.a.x + ray.b.x * obj->det;
    obj->norm.y = ray.a.y + ray.b.y * obj->det;
    obj->norm.z = ray.a.z + ray.b.z * obj->det;
}
