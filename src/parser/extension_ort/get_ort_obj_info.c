/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_ort_obj_info.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodenos <glodenos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/01 14:37:43 by glodenos          #+#    #+#             */
/*   Updated: 2016/12/14 10:39:24 by glodenos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_RT.h"

static void		init_ort_obj_info(t_env *e, size_t type)
{
	e->obj[e->elem_obj].angle = 0.0f;
	e->obj[e->elem_obj].color = 0x0;
	e->obj[e->elem_obj].diffuse = 0.0f;
	e->obj[e->elem_obj].end = 1;
	e->obj[e->elem_obj].gloss = 0.0f;
	e->obj[e->elem_obj].id = e->elem_gp;
	e->obj[e->elem_obj].pos_a = (cl_float3){0.0f, 0.0f, 0.0f};
	e->obj[e->elem_obj].pos_b = (cl_float3){0.0f, 0.0f, 0.0f};
	e->obj[e->elem_obj].pos_c = (cl_float3){0.0f, 0.0f, 0.0f};
	e->obj[e->elem_obj].radius_a = (cl_float3){0.0f, 0.0f, 0.0f};
	e->obj[e->elem_obj].radius_b = (cl_float3){0.0f, 0.0f, 0.0f};
	e->obj[e->elem_obj].reflexion = 0.0f;
	e->obj[e->elem_obj].refraction = 0.0f;
	e->obj[e->elem_obj].rotate = (cl_float3){0.0f, 0.0f, 0.0f};
	e->obj[e->elem_obj].type = type;
	e->obj[e->elem_obj].type_bump = 0;
}

static void		get_ort_obj_info_sub_2(t_env *e, char **str, size_t *i)
{
	if (!ft_strcmp_case(str[*i], "position_c"))
		get_info_position(&e->obj[e->elem_obj].pos_c, str[++*i]);
	else if (!ft_strcmp_case(str[*i], "radius_a") || \
		!ft_strcmp_case(str[*i], "radius"))
		get_info_radius(&e->obj[e->elem_obj].radius_a, str[++*i]);
	else if (!ft_strcmp_case(str[*i], "radius_b"))
		get_info_radius(&e->obj[e->elem_obj].radius_b, str[++*i]);
	else if (!ft_strcmp_case(str[*i], "reflexion"))
		e->obj[e->elem_obj].reflexion = ft_atoi(str[++*i]);
	else if (!ft_strcmp_case(str[*i], "refraction"))
		e->obj[e->elem_obj].refraction = ft_atoi(str[++*i]);
	else if (!ft_strcmp_case(str[*i], "rotate"))
		get_info_position(&e->obj[e->elem_obj].rotate, str[++*i]);
	else
	{
		ft_putendl(str[*i]);
		ft_putstr_err("ERROR: Object Invalid keyword", 1);
	}
}

static void		get_ort_obj_info_sub(t_env *e, char **str, size_t *i)
{
	if (!ft_strcmp_case(str[*i], "angle"))
		get_info_angle(e, str, i);
	else if (!ft_strcmp_case(str[*i], "bump"))
		e->obj[e->elem_obj].type_bump = ft_atoi(str[++*i]);
	else if (!ft_strcmp_case(str[*i], "color"))
		get_info_color(&e->obj[e->elem_obj].color, str[++*i]);
	else if (!ft_strcmp_case(str[*i], "diffuse"))
		get_info_diffuse(&e->obj[e->elem_obj].diffuse, str[++*i]);
	else if (!ft_strcmp_case(str[*i], "gloss"))
		++*i;
	else if (!ft_strcmp_case(str[*i], "position") \
		|| !ft_strcmp_case(str[*i], "position_a"))
		get_info_position(&e->obj[e->elem_obj].pos_a, str[++*i]);
	else if (!ft_strcmp_case(str[*i], "position_b"))
		get_info_position(&e->obj[e->elem_obj].pos_b, str[++*i]);
	else
		get_ort_obj_info_sub_2(e, str, i);
}

void			get_ort_obj_info(t_env *e, char **str, size_t *i, size_t type)
{
	if (!str[++*i])
		ft_putstr_err("ERROR: Object -> NULL ?", 1);
	if (str[*i][0] != '{')
		ft_putstr_err("ERROR: Object { ?", 1);
	init_ort_obj_info(e, type);
	while (ft_strcmp_case(str[++*i], "}"))
	{
		if (!str[*i])
			ft_putstr_err("ERROR: Object -> NULL ?", 1);
		get_ort_obj_info_sub(e, str, i);
	}
	++e->elem_obj;
	e->obj[e->elem_obj].end = 0;
}
