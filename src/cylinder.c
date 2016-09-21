/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodenos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/21 23:06:31 by glodenos          #+#    #+#             */
/*   Updated: 2016/09/21 23:10:45 by glodenos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_RT.h"

double  cylinder(t_obj obj, t_ray ray)
{
    t_evo evo;

    evo.a = ray.b.x * ray.b.x + ray.b.z * ray.b.z;
    evo.b = 2 * ((ray.a.x - obj.pos.x) * ray.b.x + (ray.b.z - obj.pos.z) *
            ray.b.z);
    evo.c = (ray.a.x - obj.pos.x) * (ray.a.x - obj.pos.x) +
            (ray.a.z - obj.pos.z) * (ray.a.z - obj.pos.z) - obj.r * obj.r;
    evo.det = evo.b * evo.b - 4 * evo.a * evo.c;
    if (evo.det > 0)
    {
        evo.ta = (-evo.b + sqrt(evo.det)) / (2 * evo.a);
        evo.tb = (-evo.b - sqrt(evo.det)) / (2 * evo.a);
        if (evo.ta > evo.tb && evo.ta < obj.r)
            return (evo.tb);
        return(evo.ta);
    }
    return (-1);
}
