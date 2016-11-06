/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_ort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodenos <glodenos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/16 20:46:58 by glodenos          #+#    #+#             */
/*   Updated: 2016/11/06 23:41:55 by glodenos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_RT.h"

/*  TODO look s_scanf*/

static inline void  init_ort_parser(t_env *e)
{
    e->config = 0;
    e->group = 0;
    e->scene = 0;
    e->camera = 0;
    e->elem_gp = 0;
    e->elem_obj = 0;
    e->elem_spt = 0;
}

static inline void  init_spotlight_obj(t_env *e, char **str)
{
    size_t  i;

    i = 0;
    e->scn.n_obj = 0;
    e->scn.n_spt = 0;
    while (str[i])
    {
        if (!ft_strcmp_case(str[i], "spotlight"))
            ++e->scn.n_spt;
        else if (!ft_strcmp_case(str[i], "cone"))
            ++e->scn.n_obj;
        else if (!ft_strcmp_case(str[i], "cylinder"))
            ++e->scn.n_obj;
        else if (!ft_strcmp_case(str[i], "plan"))
            ++e->scn.n_obj;
        else if (!ft_strcmp_case(str[i], "sphere"))
            ++e->scn.n_obj;
        else if (!ft_strcmp_case(str[i], "spotlight"))
            ++e->scn.n_obj;
        else if (!ft_strcmp_case(str[i], "torus"))
            ++e->scn.n_obj;
        ++i;
    }
    if (!(e->scn.n_obj && e->scn.n_spt))
        ft_putstr_err("ERROR: light or object not present", 1);
    if (!(e->obj = (t_obj *)ft_memalloc(sizeof(t_obj) * (e->scn.n_obj + 1))))
        ft_putstr_err("ERROR: malloc", 1);
    if (!(e->spt = (t_spt *)ft_memalloc(sizeof(t_spt) * (e->scn.n_spt + 1))))
        ft_putstr_err("ERROR: malloc", 1);
}

void    get_info_ort(t_env *e, char **str, size_t *i)
{
    if (!ft_strcmp_case(str[*i], ".config"))
        get_ort_config(e, str, i);
    else if (!ft_strcmp_case(str[*i], ".texture"))
        get_ort_texture(e, str, i);
    else if (!ft_strcmp_case(str[*i], "scene"))
        get_ort_scene(e, str, i);
    else if (!ft_strcmp_case(str[*i], "camera"))
        get_ort_camera(e, str, i);
    else if (!ft_strcmp_case(str[*i], "cone"))
        get_ort_obj_info(e, str, i, CONE);
    else if (!ft_strcmp_case(str[*i], "cylinder"))
        get_ort_obj_info(e, str, i, CYLINDER);
    else if (!ft_strcmp_case(str[*i], "plan"))
        get_ort_obj_info(e, str, i, PLAN);
    else if (!ft_strcmp_case(str[*i], "sphere"))
        get_ort_obj_info(e, str, i, SPHERE);
    else if (!ft_strcmp_case(str[*i], "torus"))
        get_ort_obj_info(e, str, i, TORUS);
    else if (!ft_strcmp_case(str[*i], "triangle"))
        get_ort_obj_info(e, str, i, TRIANGLE);
    else if (!ft_strcmp_case(str[*i], "group"))
    {
        if (e->group)
            ft_putstr_err("ERROR: Group 1 level possible", 1);
        get_ort_group(e, str, i);
        ++e->elem_gp;
    }
    else if (!ft_strcmp_case(str[*i], "spotlight"))
        get_ort_spotlight(e, str, i);
    else
    {
        ft_putstr("Value == ");
        ft_putendl(str[*i]);
        ft_putstr_err("Unknown keyword", 1);
    }
}

void    get_ort(t_env *e, char **str)
{
    size_t  i;

    i = 0;
    init_spotlight_obj(e, str);
    init_ort_parser(e);
    while (str[i])
    {
        get_info_ort(e, str, &i);
        ++i;
    }
    if (!(e->config && e->scene && e->camera))
        ft_putstr_err("ERROR: .config or scene or camera not present", 1);




    i = 0;


    printf("OBJ type %zu\n", e->obj[i].type);

    printf("OBJ pos = %f\n", e->obj[i].pos_a.x);
    printf("OBJ pos = %f\n", e->obj[i].pos_a.y);
    printf("OBJ pos = %f\n", e->obj[i].pos_a.z);

    printf("OBJ rot = %f\n", e->obj[i].rotate.x);
    printf("OBJ rot = %f\n", e->obj[i].rotate.y);
    printf("OBJ rot = %f\n", e->obj[i].rotate.z);


    printf("OBJ radius = %f\n", e->obj[i].radius_a.x);
    printf("OBJ radius = %f\n", e->obj[i].radius_a.y);
    printf("OBJ radius = %f\n", e->obj[i].radius_a.z);


    printf("OBJ color = %X\n", e->obj[i].color);










}
