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

void    run_object(t_obj *obj, t_ray ray)
{
    if (obj->type == 1)
        cone(obj, ray);
    else if (obj->type == 2)
        cylinder(obj, ray);
    else if (obj->type == 3)
        plan(obj, ray);
    else if (obj->type == 4)
        sphere(obj, ray);
}
