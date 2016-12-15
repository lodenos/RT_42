/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_ort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cducaffy <cducaffy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 13:53:25 by cducaffy          #+#    #+#             */
/*   Updated: 2016/12/15 13:27:44 by opettex-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_rt.h"

static	void			init_spotlight_obj_sub(t_env *e, char *str)
{
	if (!ft_strcmp_case(str, "spotlight"))
		++e->scn.n_spt;
	else if (!ft_strcmp_case(str, "cone"))
		++e->scn.n_obj;
	else if (!ft_strcmp_case(str, "cylinder"))
		++e->scn.n_obj;
	else if (!ft_strcmp_case(str, "plan"))
		++e->scn.n_obj;
	else if (!ft_strcmp_case(str, "sphere"))
		++e->scn.n_obj;
	else if (!ft_strcmp_case(str, "spotlight"))
		++e->scn.n_obj;
	else if (!ft_strcmp_case(str, "torus"))
		++e->scn.n_obj;
	else if (!ft_strcmp_case(str, "triangle"))
		++e->scn.n_obj;
	else if (!ft_strcmp_case(str, "ellipsoid"))
		++e->scn.n_obj;
}

static inline void		init_spotlight_obj(t_env *e, char **str)
{
	size_t i;

	i = 0;
	e->scn.n_obj = 0;
	e->scn.n_spt = 0;
	while (str[i])
	{
		init_spotlight_obj_sub(e, str[i]);
		++i;
	}
	if (!(e->scn.n_obj && e->scn.n_spt))
		ft_putstr_err("ERROR: light or object not present", 1);
	if (!(e->obj = (t_obj *)ft_memalloc(sizeof(t_obj) * (e->scn.n_obj + 1))))
		ft_putstr_err("ERROR: malloc", 1);
	if (!(e->spt = (t_spt *)ft_memalloc(sizeof(t_spt) * (e->scn.n_spt + 1))))
		ft_putstr_err("ERROR: malloc", 1);
}

static void				get_info_ort_sub(t_env *e, char **str, size_t *i)
{
	if (!ft_strcmp_case(str[*i], "group"))
	{
		++e->elem_gp;
		if (e->group)
			ft_putstr_err("ERROR: Group 1 level possible", 1);
		get_ort_group(e, str, i);
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

void					get_info_ort(t_env *e, char **str, size_t *i)
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
	else if (!ft_strcmp_case(str[*i], "ellipsoid"))
		get_ort_obj_info(e, str, i, ELLIPSOID);
	else
		get_info_ort_sub(e, str, i);
}

void					get_ort(t_env *e, char **str)
{
	size_t i;

	i = 0;
	init_spotlight_obj(e, str);
	init_ort_parser(e);
	while (str[i])
	{
		get_info_ort(e, str, &i);
		++i;
		++e->elem_gp;
	}
	if (!(e->config && e->scene && e->camera))
		ft_putstr_err("ERROR: .config or scene or camera not present", 1);
}
