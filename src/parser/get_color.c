/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodenos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/26 15:19:21 by glodenos          #+#    #+#             */
/*   Updated: 2016/09/26 17:35:15 by glodenos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_RT.h"

t_rgba  get_color(char *str)
{
    register int    i;
    char            **tmp;
    register t_rgba color;
    register int    rgba;

    i = -1;
    while (str[++i])
        if (str[i] < '0' || str[i] > '9')
            if (str[i] != '/')
                ft_putstr_err("ERROR: Init. color.char", 1);
    tmp = ft_strsplit(str, '/');
    if (ft_strlen_tab(tmp) != 4)
        ft_putstr_err("ERROR: Init. color.argument", 1);
    ((rgba = atoi(tmp[0])) > 255) ?
        ft_putstr_err("ERROR: Init. color.max > 255", 1) :
        (color.red = (unsigned char)rgba);
    ((rgba = atoi(tmp[1])) > 255) ?
        ft_putstr_err("ERROR: Init. color.max > 255", 1) :
        (color.green = (unsigned char)rgba);
    ((rgba = atoi(tmp[2])) > 255) ?
        ft_putstr_err("ERROR: Init. color.max > 255", 1) :
        (color.blue = (unsigned char)rgba);
    ((rgba = atoi(tmp[3])) > 255) ?
        ft_putstr_err("ERROR: Init. color.max > 255", 1) :
        (color.alpha = (unsigned char)rgba);
    free_tab((void **)tmp);
    return (color);
}
