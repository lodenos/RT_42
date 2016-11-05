/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cone.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodenos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/26 01:19:46 by glodenos          #+#    #+#             */
/*   Updated: 2016/10/05 15:34:08 by glodenos         ###   ########.fr       */
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

inline static float     get_value_float(char *str)
{
    register int    i;
    register float  val;

    i = -1;
    while (str[++i])
        if (str[i] < '0' || str[i] > '9')
            if (str[i] != '.')
                ft_putstr_err("ERROR: Init. cone.double", 1);
    if ((int)(val = (float)atof(str)) > 180)
        ft_putstr_err("ERROR: Init. cone.max > 180", 1);
    return (val);
}

void                    get_cone(t_obj *obj, char **line)
{
    if (ft_strlen_tab(line) != 6)
        ft_putstr_err("ERROR: Init. Object.cone.nbr.argument", 1);
    obj->pos = get_vec3(line[1]);
    obj->rotate = normalize(get_vec3(line[2]));
    obj->color = get_color(line[3]);
    obj->radius = get_radius(line[4]);
    obj->angle = tanf((get_value_float(line[5]) * (float)(M_PI / 180)));
    obj->type = 1;
    obj->end = 1;
}