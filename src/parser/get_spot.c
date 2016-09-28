/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_spot.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodenos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/26 14:23:17 by glodenos          #+#    #+#             */
/*   Updated: 2016/09/26 16:55:35 by glodenos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_RT.h"

inline static char  get_value_char(char *str)
{
    register int    i;
    register int    val;

    i = -1;
    while (str[++i])
        if (str[i] < '0' || str[i] > '9')
            ft_putstr_err("ERROR: Init. spot.char", 1);
    if ((val = atoi(str)) > 100)
        ft_putstr_err("ERROR: Init. spot.max > 100", 1);
    return ((char)val);
}

void                get_spot(t_spt *spt, char **line)
{
    if (ft_strlen_tab(line) != 5)
        ft_putstr_err("ERROR: Init. Spot.nbr.argument", 1);
    spt->pos = get_vec3(line[1]);
    spt->rgba = get_color(line[2]);
    spt->light = get_value_char(line[3]);
    spt->ambient = get_value_char(line[4]);
    spt->end = 1;
}
