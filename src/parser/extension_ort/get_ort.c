/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_ort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodenos <glodenos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/16 20:46:58 by glodenos          #+#    #+#             */
/*   Updated: 2016/10/30 12:53:27 by glodenos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_RT.h"


static inline void  init_ort_parser(t_env *e)
{
    e->config = 0;
}

void    get_ort(t_env *e, char **str)
{
    size_t  i;

    i = 0;
    init_ort_parser(e);
    while (str[i])
    {
        if (ft_strcmp(str[i], ".config") == 0)
            get_ort_config(e, str, &i);
        else if (ft_strcmp(str[i], ".texture") == 0)
            get_ort_texture(e, str, &i);
        else if (ft_strcmp(str[i], "scene") == 0)
            get_ort_scene(e, str, &i);
        else if (ft_strcmp(str[i], "Scene") == 0)
            get_ort_scene(e, str, &i);
        else if (ft_strcmp(str[i], "SCENE") == 0)
            get_ort_scene(e, str, &i);
        else if (ft_strcmp(str[i], "cone") == 0)
            get_ort_cone(e, str, &i);
        else if (ft_strcmp(str[i], "Cone") == 0)
            get_ort_cone(e, str, &i);
        else if (ft_strcmp(str[i], "CONE") == 0)
            get_ort_cone(e, str, &i);
        else if (ft_strcmp(str[i], "cylinder") == 0)
            get_ort_cylinder(e, str, &i);
        else if (ft_strcmp(str[i], "Cylinder") == 0)
            get_ort_cylinder(e, str, &i);
        else if (ft_strcmp(str[i], "CYLINDER") == 0)
            get_ort_cylinder(e, str, &i);
        else if (ft_strcmp(str[i], "group") == 0)
            get_ort_group(e, str, &i);
        else if (ft_strcmp(str[i], "Group") == 0)
            get_ort_group(e, str, &i);
        else if (ft_strcmp(str[i], "GROUP") == 0)
            get_ort_group(e, str, &i);
        else if (ft_strcmp(str[i], "plan") == 0)
            get_ort_plan(e, str, &i);
        else if (ft_strcmp(str[i], "Plan") == 0)
            get_ort_plan(e, str, &i);
        else if (ft_strcmp(str[i], "PLAN") == 0)
            get_ort_plan(e, str, &i);
        else if (ft_strcmp(str[i], "sphere") == 0)
            get_ort_sphere(e, str, &i);
        else if (ft_strcmp(str[i], "Sphere") == 0)
            get_ort_sphere(e, str, &i);
        else if (ft_strcmp(str[i], "SPHERE") == 0)
            get_ort_sphere(e, str, &i);
        else if (ft_strcmp(str[i], "torus") == 0)
            get_ort_torus(e, str, &i);
        else if (ft_strcmp(str[i], "Torus") == 0)
            get_ort_torus(e, str, &i);
        else if (ft_strcmp(str[i], "TORUS") == 0)
            get_ort_torus(e, str, &i);
        else
        {
            ft_putendl(str[i]);
            ft_putstr_err("Unknown keyword", 1);
        }
        ++i;
    }
}
