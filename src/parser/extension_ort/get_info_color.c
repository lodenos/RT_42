/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_info_color.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodenos <glodenos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/01 15:16:07 by glodenos          #+#    #+#             */
/*   Updated: 2016/11/06 16:44:03 by glodenos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_RT.h"

static inline void  get_color_hexa(unsigned int *color, char *str)
{
    size_t  i;
    size_t  j;

    *color = 0;
    if ((i = ft_strlen(str)) > 8 || i < 3)
        ft_putstr_err("ERROR: Color Hex len > 8 || len < 3", 1);
    if (!(str[0] == '0' && (str[1] == 'x' || str[1] == 'X')))
        ft_putstr_err("ERROR: Color no Hexa", 1);
    i = 2;
    while (str[i])
    {
        if (str[i] < '0' || str[i] > '9')
            if (str[i] < 'a' || str[i] > 'f')
                if (str[i] < 'A' || str[i] > 'F')
                    ft_putstr_err("ERROR: Color no Hexa", 1);
        ++i;
    }
    i = 2;
    while (str[i])
    {
        if (str[i] >= 'a' && str[i] <= 'f')
            *color = *color * 10 + 10 + 'a' - str[i];
        else if (str[i] >= 'A' && str[i] <= 'F')
            *color = *color * 10 + 10 + 'A' - str[i];
        else
            *color = *color * 10 + str[i] - 30;
        ++i;
    }
}

void                get_info_color(unsigned int *color, char *str)
{
    size_t          i;
    size_t          j;
    char            **tmp;
    unsigned int    value;

    i = 0;
    j = 0;
    if (!str)
        ft_putstr_err("ERROR: .ort == NULL", 1);
    tmp = ft_strsplit(str, '/');
    if (ft_strlen_tab(tmp) == 1)
        return (get_color_hexa(color, str));
    if (ft_strlen_tab(tmp) != 3)
        ft_putstr_err("ERROR: Color decimal < 3 || > 3", 1);
    while (tmp[i][j])
    {
        while (tmp[i][j])
        {
            if (tmp[i][j] < '0' || tmp[i][j] > '9')
                ft_putstr_err("ERROR: Color no decimal", 1);
            ++j;
        }
        ++i;
    }
    if ((value = (unsigned int)ft_atoi(tmp[0])) > 255)
        ft_putstr_err("ERROR: Color red > 255", 1);
    *color = *color | value << 24;
    if ((value = (unsigned int)ft_atoi(tmp[1])) > 255)
        ft_putstr_err("ERROR: Color red > 255", 1);
    *color = *color | value << 16;
    if ((value = (unsigned int)ft_atoi(tmp[2])) > 255)
        ft_putstr_err("ERROR: Color red > 255", 1);
    *color = *color | value << 8 | 0xFF;
    free_tab((void **)tmp);
}
