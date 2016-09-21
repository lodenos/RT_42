/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodenos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/21 22:28:24 by glodenos          #+#    #+#             */
/*   Updated: 2016/09/21 22:46:40 by glodenos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_RT.h"

double  cone(t_obj obj, t_ray ray)
{
    t_evo evo;

    evo.a = ray.b.x * ray.b.x + ray.b.z *ray.b.z - ray.b.y * ray.b.y;
    evo.b = 2 * ((ray.a.x - obj.pos.x) * ray.b.x + (ray.a.z - obj.pos.z) * \
            ray.b.z - (ray.a.y - obj.pos.y) * ray.b.y);
    evo.c = (ray.a.x - obj.pos.x) * (ray.a.x - obj.pos.x) + \
            (ray.a.z - obj.pos.z) * (ray.a.z - obj.pos.z) - \
            (ray.a.y - obj.pos.y) * (ray.a.y - obj.pos.y);
    evo.det = evo.b * evo.b - 4 * (evo.a * evo.c);
    if (evo.det >= 0)
    {
        evo.ta = (-evo.b + sqrt(evo.det)) / (2 * evo.a);
        evo.tb = (-evo.b - sqrt(evo.det)) / (2 * evo.a);
        if (evo.ta > evo.tb)
            return (evo.tb);
        return (evo.ta);
    }
    return (-1);
}
