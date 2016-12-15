/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_ort_spotlight.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodenos <glodenos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/31 11:31:53 by glodenos          #+#    #+#             */
/*   Updated: 2016/12/15 13:29:09 by opettex-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_rt.h"

static inline void		init_ort_spotlight(t_env *e)
{
	e->spt[e->elem_spt].end = 1;
	e->spt[e->elem_spt].id = e->elem_gp;
	e->spt[e->elem_spt].light = 1;
	e->spt[e->elem_spt].pos = (cl_float3){0, 0, 0};
	e->spt[e->elem_spt].color = 0xFFFFFFFF;
}

void					get_ort_spotlight(t_env *e, char **str, size_t *i)
{
	init_ort_spotlight(e);
	if (!str[*i])
		ft_putstr_err("ERROR: .ort spotlight == NULL", 1);
	if (!str[++*i] && ft_strcmp(str[*i], "{") == 0)
		ft_putstr_err("ERROR: spotlight {", 1);
	while (ft_strcmp(str[++*i], "}") != 0)
	{
		if (!str[*i])
			ft_putstr_err("ERROR: spotlight incomplete", 1);
		if (ft_strcmp_case(str[*i], "power") == 0)
			++*i;
		else if (ft_strcmp_case(str[*i], "position") == 0)
			get_info_position(&e->spt[e->elem_spt].pos, str[++*i]);
		else if (ft_strcmp_case(str[*i], "color") == 0)
			++*i;
		else
			ft_putstr_err("ERROR: spotlight flags Unknown", 1);
	}
	++e->elem_spt;
	e->spt[e->elem_spt].end = 0;
}
