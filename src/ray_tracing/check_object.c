/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_object.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodenos <glodenos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/28 21:01:21 by glodenos          #+#    #+#             */
/*   Updated: 2016/12/07 13:15:04 by glodenos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_RT.h"

inline float    check_object(t_obj *obj, register t_ray ray, size_t *id, size_t mask)
{
    register float  det;
    register size_t i;
    register float  tmp_det;

    i = 0;
    *id = 0;
    tmp_det = 20000;
    while (obj[i].end)
    {
        if (i == mask)
        {
            ++i;
            continue ;
        }
        det = run_object(obj[i], ray);
        if (0 < det && det < tmp_det)
        {
            tmp_det = det;
            *id = (size_t)i;
        }
        ++i;
    }
    if (tmp_det == 20000)
        return -1;
    return (tmp_det);
}
