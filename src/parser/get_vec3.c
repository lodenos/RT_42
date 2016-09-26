/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_vec3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodenos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/25 22:31:08 by glodenos          #+#    #+#             */
/*   Updated: 2016/09/26 20:14:14 by glodenos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_RT.h"

t_vec3  get_vec3(char *str)
{
    register int    i;
    char            **tmp;
    register t_vec3 vect;

    i = -1;
    while (str[++i])
        if (str[i] < '0' || str[i] > '9')
            if (str[i] != '/' && str[i] != '-' && str[i] != '.') 
                ft_putstr_err("ERROR: Init. vec3.char", 1); 
    tmp = ft_strsplit(str, '/');
    if (ft_strlen_tab(tmp) != 3)
        ft_putstr_err("ERROR: Init. vec3.argument", 1);
    vect.x = atof(tmp[0]);
    vect.y = atof(tmp[1]);
    vect.z = atof(tmp[2]);
    free_tab((void **)tmp);
    return (vect);
}
