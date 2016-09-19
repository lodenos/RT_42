/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodenos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/14 22:10:12 by glodenos          #+#    #+#             */
/*   Updated: 2016/09/01 05:28:40 by glodenos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_RT.h"

double  sphere(t_obj obj, t_ray ray)
{
    t_evo   evo;

    /*  Quadratic of the form   */
    evo.a = ray.b.x * ray.b.x + ray.b.y * ray.b.y + ray.b.z * ray.b.z;
    evo.b = 2 * (ray.a.x * ray.b.x + ray.a.y * ray.b.y + ray.a.z * ray.b.z  \
        - ray.b.x * obj.pos.x - ray.b.y * obj.pos.y - ray.b.z * obj.pos.z);
    evo.c = ray.a.x * ray.a.x - 2 * ray.a.x * obj.pos.x + obj.pos.x *       \
        obj.pos.x + ray.a.y * ray.a.y - 2 * ray.a.y * obj.pos.y +           \
        obj.pos.y * obj.pos.y + ray.a.z * ray.a.z - 2 * obj.pos.z *         \
        obj.pos.z + obj.pos.z * obj.pos.z - obj.r * obj.r;
    evo.det = evo.b * evo.b - 4 * evo.a * evo.c;
    if (evo.det >= 0)
    {
        evo.ta = (-evo.b - sqrt(evo.det)) / (2 * evo.a);
        evo.tb = (-evo.b + sqrt(evo.det)) / (2 * evo.a);
        if (evo.ta > evo.tb)
            return (evo.ta);
        return (evo.tb);
    }
    return (-1);
}
