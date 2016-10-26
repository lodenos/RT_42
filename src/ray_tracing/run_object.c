/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_object.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodenos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 21:43:14 by glodenos          #+#    #+#             */
/*   Updated: 2016/10/04 21:58:31 by glodenos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_RT.h"

inline float    run_object(register t_obj obj, register t_ray ray)
{
    if (obj.type == 1)
        return (cone(obj, ray));
    else if (obj.type == 2)
        return (cylinder(obj, ray));
    else if (obj.type == 3)
        return (plan(obj, ray));
    else if (obj.type == 4)
        return (sphere(obj, ray));
    return (-1);
}
