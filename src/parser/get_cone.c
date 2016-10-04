/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cone.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodenos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/26 01:19:46 by glodenos          #+#    #+#             */
/*   Updated: 2016/10/04 21:40:42 by glodenos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_RT.h"

static inline int       get_radius(char *str)
{
    register int    i;

    i = -1;
    while (str[++i])
        if (str[i] < '0' || str[i] > '9')
            ft_putstr_err("ERROR: Init. Object.cone.char.radius", 1);
    return (atoi(str));
}

inline static double    get_value_double(char *str)
{
    register int    i;
    register double val;

    i = -1;
    while (str[++i])
        if (str[i] < '0' || str[i] > '9')
            if (str[i] != '.')
                ft_putstr_err("ERROR: Init. cone.double", 1);
    if ((int)(val = atof(str)) > 180)
        ft_putstr_err("ERROR: Init. cone.max > 180", 1);
    return (val);
}

void                    get_cone(t_obj *obj, char **line)
{
    if (ft_strlen_tab(line) != 6)
        ft_putstr_err("ERROR: Init. Object.cone.nbr.argument", 1);
    obj->pos = get_vec3(line[1]);
    obj->rotate = get_vec3(line[2]);
    obj->rgba = get_color(line[3]);
    obj->radius = get_radius(line[4]);
    obj->angle = tan((get_value_double(line[5]) * (M_PI / 180)));
    obj->type = 1;
    obj->end = 1;
}
