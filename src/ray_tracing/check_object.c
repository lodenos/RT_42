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

inline size_t   check_object(t_obj *obj, t_ray *ray)
{
    register int    i;
    register size_t id;
    register float  tmp_det;

    i = -1;
    id = 0;
    tmp_det = 20000;
    ray->rgba = (t_rgba){0, 0, 0, 255};
    while (obj[++i].end)
    {
        run_object(&obj[i], *ray);
        if (0 <= obj[i].det && obj[i].det <= tmp_det)
            tmp_det = obj[(id = (size_t)i)].det;
    }
    return (id);
}
