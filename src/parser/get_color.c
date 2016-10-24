/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodenos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/26 15:19:21 by glodenos          #+#    #+#             */
/*   Updated: 2016/09/26 19:33:44 by glodenos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_RT.h"

static inline unsigned int  ft_err(void)
{
    ft_putstr_err("ERROR: Init. color.max > 255", 1);
    return (0);
}

unsigned int    get_color(char *str)
{
    register unsigned int   color;
    register int            i;
    register unsigned char  rgba;
    char                    **tmp;

    i = -1;
    while (str[++i])
        if (str[i] < '0' || str[i] > '9')
            if (str[i] != '/')
                ft_putstr_err("ERROR: Init. color.char", 1);
    tmp = ft_strsplit(str, '/');
    if (ft_strlen_tab(tmp) != 4)
        ft_putstr_err("ERROR: Init. color.argument", 1);
    color = ((rgba = (unsigned char)atoi(tmp[0])) > 255) ? ft_err() :
            color | (unsigned int)rgba << 24;
    color = ((rgba = (unsigned char)atoi(tmp[0])) > 255) ? ft_err() :
            color | (unsigned int)rgba << 16;
    color = ((rgba = (unsigned char)atoi(tmp[0])) > 255) ? ft_err() :
            color | (unsigned int)rgba << 8;
    color = ((rgba = (unsigned char)atoi(tmp[0])) > 255) ? ft_err() :
            color | (unsigned int)rgba;
    return (color);
}
