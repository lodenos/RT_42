/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   diffused_light.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodenos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/19 00:39:00 by glodenos          #+#    #+#             */
/*   Updated: 2016/08/30 22:12:06 by glodenos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_RT.h"

double  diffused_light(t_obj obj, t_ray ray)
{
    double  a;
    double  b;
    double  c;

    a = sqrt(((ray.a.x - obj.pos.x) * (ray.a.x - obj.pos.x)) +    \
            ((ray.a.y - obj.pos.y) * (ray.a.y - obj.pos.y)) +     \
            ((ray.a.z - obj.pos.z) * (ray.a.z - obj.pos.z)));
    b = sqrt(((obj.norm.x - obj.pos.x) * (obj.norm.x - obj.pos.x)) +    \
            ((obj.norm.y - obj.pos.y) * (obj.norm.y - obj.pos.y)) +     \
            ((obj.norm.z - obj.pos.z) * (obj.norm.z - obj.pos.z)));
    c = sqrt(((ray.a.x - obj.norm.x) * (ray.a.x - obj.norm.x)) +  \
            ((ray.a.y - obj.norm.y) * (ray.a.y - obj.norm.y)) +   \
            ((ray.a.z - obj.norm.z) * (ray.a.z - obj.norm.z)));
    return (1 - cos(asin(((a * a) + (b * b) - (c * c)) / (2 * a * b))));
}
