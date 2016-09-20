/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_object.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anespoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/13 13:59:33 by anespoul          #+#    #+#             */
/*   Updated: 2016/09/16 12:55:27 by anespoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	o_type(t_env *e, char *type, int o)
{
	if (ft_strstr(type, "plan"))
		e->scn.obj[o].ft = &(plan);
	else if (ft_strstr(type, "sphere"))
		e->scn.obj[o].ft = &(sphere);
	else if (ft_strstr(type, "cone"))
		e->scn.obj[o].ft = &(cone);
	else if (ft_strstr(type, "torus"))
		e->scn.obj[o].ft = &(torus);
	else if (ft_strstr(type, "cylinder"))
		e->scn.obj[o].ft = &(cylinder);
}

void	get_obj(t_env *e, char *data, int o, int index)
{
	char	**xyz;

	xyz = ft_strsplit(data, ' ');
	if (index == 0)
		e->scn.obj[o].rgb = (t_rgb){ft_atoi(xyz[0]), ft_atoi(xyz[1]),\
			ft_atoi(xyz[2]),};
	else if (index == 1)
		e->scn.obj[o].pos = (t_vec3d){ft_atoi(xyz[0]), ft_atoi(xyz[1]),\
			ft_atoi(xyz[2])};
	else if (index == 2)
		e->scn.obj[o].rot = (t_vec3d){ft_atoi(xyz[0]), ft_atoi(xyz[1]),\
			ft_atoi(xyz[2])};
	free(xyz);
}

void	get_objectinfo(t_env *e, t_list *list, int o)
{
	while (list && !ft_strstr(list->content, "{"))
		list = list->next;
	while (list && !ft_strstr(list->content, "}"))
	{
		if (ft_strstr(list->content, "color"))
			get_obj(e, ft_strconc(list->content, '(', ')'), o, 0);
		else if (ft_strstr(list->content, "pos"))
			get_obj(e, ft_strconc(list->content, '(', ')'), o, 1);
		else if (ft_strstr(list->content, "rot"))
			get_obj(e, ft_strconc(list->content, '(', ')'), o, 2);
		else if (ft_strstr(list->content, "size"))
			e->scn.obj[o].r = ft_atoi(ft_strconc(list->content, '(', ')'));
		list = list->next;
	}
}
void	init_obj(t_env *e, int index, int s, int o)
{
	if (index == 0)
	{
		e->scn.spt[s].rgb = (t_rgb){255, 255, 255};
		e->scn.spt[s].pos = (t_vec3d){800, 800, 800};
		e->scn.spt[s].light = 100;
		e->scn.spt[s].end = 1;
	}
	else
	{
		e->scn.obj[o].rgb = (t_rgb){0, 0, 0};
		e->scn.obj[o].pos = (t_vec3d){0, 0, 0};
		e->scn.obj[o].r = 0;
		e->scn.obj[o].det = 20000;
		e->scn.obj[o].end = 1;
	}
}

void	get_object(t_env *e, t_list *list, int s, int o)
{
	while (list && !ft_strstr(list->content, "{"))
		list = list->next;
	while (list && !ft_strstr(list->content, "}"))
	{
		if (ft_strstr(list->content, "spot"))
		{
			init_obj(e, 0, s, o);
			get_spotinfo(e, list, s);
			s++;
		}
		else if (ft_strstr(list->content, "object"))
		{
			init_obj(e, 1, s, o);
			o_type(e, ft_strconc(list->content, '(', ')'), o);
			get_objectinfo(e, list, o);
			o++;
		}
		list = list->next;
		if (ft_strstr(list->next->content, "object") || \
				ft_strstr(list->next->content, "spot"))
			list = list->next;
	}
	e->scn.obj[o].end = 0;
	e->scn.spt[s].end = 0;
}
