/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_object.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodenos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/28 21:01:21 by glodenos          #+#    #+#             */
/*   Updated: 2016/10/05 15:36:28 by glodenos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_RT.h"

inline float    check_object(t_obj *obj, register t_ray ray, size_t *id)
{
    register float  det;
    register size_t i;
    register float  tmp_det;

    i = 0;
    tmp_det = 20000;
    while (obj[i].end)
    {
        det = run_object(obj[i], ray);
        if (0 < det && det < tmp_det)
        {
            tmp_det = det;
            *id = (size_t)i;
        }
        ++i;
    }
    return (tmp_det);
}
