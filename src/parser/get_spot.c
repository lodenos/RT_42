/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_spot.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodenos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/26 14:23:17 by glodenos          #+#    #+#             */
/*   Updated: 2016/10/05 15:35:45 by glodenos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_RT.h"

inline static float get_value_float(char *str)
{
    register int    i;
    register float  val;

    i = -1;
    while (str[++i])
        if (str[i] < '0' || str[i] > '9')
            if (str[i] != '.')
                ft_putstr_err("ERROR: Init. spot.double", 1);
    if ((int)(val = (float)atof(str)) > 1)
        ft_putstr_err("ERROR: Init. spot.max > 1", 1);
    return (val);
}

void                get_spot(t_spt *spt, char **line)
{
    if (ft_strlen_tab(line) != 7)
        ft_putstr_err("ERROR: Init. Spot.nbr.argument", 1);
    spt->pos = get_vec3(line[1]);
    spt->rgba = get_color(line[2]);
    spt->light = get_value_float(line[3]);
    spt->ambient = get_value_float(line[4]);
    spt->specular = get_value_float(line[5]);
    spt->diffuse = get_value_float(line[6]);
    spt->end = 1;
}
