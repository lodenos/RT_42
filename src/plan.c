/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plan.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodenos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/21 23:07:21 by glodenos          #+#    #+#             */
/*   Updated: 2016/09/21 23:15:22 by glodenos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_RT.h"

double      plan(t_obj obj, t_ray ray)
{
    double  det;
    (void)obj;

    det = -((vector_scalar(obj.rot, ray.a) - 
                vector_scalar(obj.rot, obj.pos)) /
                vector_scalar(obj.rot, ray.b));
    if (det < 0)
        return (-1);
    return (det);
}
