/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_spot.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anespoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/13 14:01:23 by anespoul          #+#    #+#             */
/*   Updated: 2016/09/16 13:01:15 by anespoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	get_spot(t_env *e, char *data, int s, int index)
{
	char **xyz;

	xyz = ft_strsplit(data, ' ');
	if (index == 0)
		e->scn.spt[s].rgb = (t_rgb){ft_atoi(xyz[0]), ft_atoi(xyz[1]),\
		ft_atoi(xyz[2])};
	else if (index == 1)
		e->scn.spt[s].pos = (t_vec3d){ft_atoi(xyz[0]), ft_atoi(xyz[1]),\
		ft_atoi(xyz[2])};
	free(xyz);
}

void	get_spotinfo(t_env *e, t_list *list, int s)
{
	while (list && !ft_strstr(list->content, "{"))
		list = list->next;
	while (list && !ft_strstr(list->content, "}"))
	{
		if (ft_strstr(list->content, "color"))
			get_spot(e, ft_strconc(list->content, '(', ')'), s, 0);
		else if (ft_strstr(list->content, "pos"))
			get_spot(e, ft_strconc(list->content, '(', ')'), s, 1);
		else if (ft_strstr(list->content, "power"))
			e->scn.spt[s].light = ft_atoi(ft_strconc(list->content, '(', ')'));
		list = list->next;
	}
}
