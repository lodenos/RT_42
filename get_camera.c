/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodenos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/16 11:18:53 by glodenos          #+#    #+#             */
/*   Updated: 2016/09/21 14:49:48 by anespoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	camera(t_env *e)
{
	t_vec3d	vpul;
	t_vec3d	upvec;
	t_vec3d	rightvec;
	t_vec3d	uu;
	t_vec3d vv;
	float	x_indent;
	float	y_indent;

	upvec = (t_vec3d){0, 1, 0};
	rightvec = (t_vec3d){1, 0, 0};
	uu = vecdot2(&upvec, 0.5 / 2.0f);
	vv = vecdot2(&rightvec, 0.35 / 2.0f);

	vpul = vecadd(&e->scn.cam.dir, &uu);
	vpul = vecsub(&vpul, &vv);
	vpul = vecadd(&e->scn.cam.pos, &vpul);

	x_indent = 0.35 / (float)e->hei;
	y_indent = 0.5 / (float)e->wid;

	vv = vecdot2(&rightvec, (e->pos.x * x_indent));
	uu = vecdot2(&upvec, (e->pos.y * y_indent));
	
	e->ray.rd = vecadd(&vpul, &vv);
	e->ray.rd = vecsub(&e->ray.rd, &uu);
	
	vecnorm(&e->ray.rd);
	e->ray.ro = e->scn.cam.pos;


/*	e->scn.cam.dir.x = e->pos.x - (e->wid / 2);
	e->scn.cam.dir.y = e->pos.y - (e->hei / 2);
	e->scn.cam.dir.z = -(e->wid / (2 * tan(FOV / 2)));
	vecnorm(&e->scn.cam.dir);
	e->ray.rd = vecsub(&e->scn.cam.dir, &e->scn.cam.pos);
	vecnorm(&e->ray.rd);
	e->ray.ro = e->scn.cam.pos;
*/

}

void	get_camera(t_env *e, char *cam, int index)
{
	char	**data;

	data = NULL;
	if (cam)
	{
		data = ft_strsplit(cam, ' ');
		if (index == 0)
			e->scn.cam.pos = (t_vec3d){ft_atoi(data[0]), ft_atoi(data[1]),\
				ft_atoi(data[2])};
		if (index == 1)
			e->scn.cam.dir = (t_vec3d){ft_atoi(data[0]), ft_atoi(data[1]),\
				ft_atoi(data[2])};
		if (index == 2)
		{
			e->wid = ft_atoi(data[0]);
			e->hei = ft_atoi(data[1]);
		}
	}
	free(data);
}

void	get_scene(t_env *e, t_list *list)
{
	while (list && !ft_strstr(list->content, "{"))
		list = list->next;
	while (list && !ft_strstr(list->content, "}"))
	{
		if (ft_strstr(list->content, "cam_pos"))
			get_camera(e, ft_strconc(list->content, '(', ')'), 0);
		else if (ft_strstr(list->content, "cam_dir"))
			get_camera(e, ft_strconc(list->content, '(', ')'), 1);
		else if (ft_strstr(list->content, "render"))
			get_camera(e, ft_strconc(list->content, '(', ')'), 2);
		list = list->next;
	}
}
