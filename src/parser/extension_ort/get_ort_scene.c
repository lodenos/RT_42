/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_ort_scene.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodenos <glodenos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/30 12:06:05 by glodenos          #+#    #+#             */
/*   Updated: 2016/10/31 14:59:58 by glodenos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_RT.h"

static inline void  init_ort_scene(t_env *e)
{
    e->scn.ambient = 0.0f;
    e->scn.specular = 50.0f;
}

void                get_ort_scene(t_env *e, char **str, size_t *i)
{
    size_t  j;

    init_ort_scene(e);
    if (e->scene)
        ft_putstr_err("ERROR: scene is already initialized", 1);
    if (!str[*i])
        ft_putstr_err("ERROR: .ort scene == NULL", 1);
    if (!str[++*i] && ft_strcmp(str[*i], "{") == 0)
        ft_putstr_err("ERROR: scene {", 1);
    while (ft_strcmp(str[++*i], "}") != 0)
    {
        if (!str[*i])
            ft_putstr_err("ERROR: scene incomplete", 1);
        if (ft_strcmp(str[*i], "ambient") == 0)
        {
            j = 0;
            ++*i;
            if (!str[*i])
                ft_putstr_err("ERROR: scene incomplete", 1);
            while (str[*i][j])
            {
                if (str[*i][j] < '0' || str[*i][j] > '9')
                    ft_putstr_err("ERROR: scene flags ambient value is not digital    1", 1);
                ++j;
            }
            if ((int)(e->scn.ambient = (float)atof(str[*i])) < 0 || (int)e->scn.ambient > 100)
                ft_putstr_err("ERROR: scene flags ambient value is < 0 | > 100", 1);
            e->scn.ambient /= 100;
        }
        else if (ft_strcmp(str[*i], "specular") == 0)
        {
            j = 0;
            ++*i;
            if (!str[*i])
                ft_putstr_err("ERROR: scene incomplete", 1);
            while (str[*i][j])
            {
                if (str[*i][j] < '0' || str[*i][j] > '9')
                    ft_putstr_err("ERROR: scene flags specular value is not digital   2", 1);
                ++j;
            }
            if ((int)(e->scn.ambient = (float)atof(str[*i])) < 0 || (int)e->scn.specular > 100)
                ft_putstr_err("ERROR: scene flags specular value is < 0 | > 100", 1);
//----------    ADD
        }
    }
    e->scene = 1;
}
