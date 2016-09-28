/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_object.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodenos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/28 21:01:21 by glodenos          #+#    #+#             */
/*   Updated: 2016/09/28 22:32:15 by glodenos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_RT.h"

inline size_t   check_object(t_obj *obj, t_ray *ray)
{
    register int    i;
    register size_t id;
    register double tmp_det;

    i = -1;
    id = 0;
    tmp_det = 20000;
    ray->rgba = (t_rgba){0, 0, 0, 255};
    while (obj[++i].end)
    {
        obj[i].ft(&obj[i], *ray);
        if (0 <= obj[i].det && obj[i].det <= tmp_det)
            tmp_det = obj[(id = (size_t)i)].det;
    }
    return (id);
}
