/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_ort_camera.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodenos <glodenos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/31 15:04:32 by glodenos          #+#    #+#             */
/*   Updated: 2016/12/15 14:20:13 by glodenos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_rt.h"

static inline void		init_ort_camera(t_env *e)
{
	e->scn.cam.fov = 1;
	e->scn.cam.h = 540;
	e->scn.cam.pos = (cl_float3){{0, 0, 0}};
	e->scn.cam.rotate = (cl_float3){{0, 0, 0}};
	e->scn.cam.w = 960;
}

static void				get_info_resolution_sub(char **tmp)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (tmp[i])
	{
		j = 0;
		if (ft_strlen(tmp[i]) > 4)
			ft_putstr_err("ERROR: the length of the number is too large", 1);
		while (tmp[i][j])
		{
			if (tmp[i][j] < '0' || tmp[i][j] > '9')
			{
				if (tmp[i][j] == '-')
					ft_putstr_err("ERROR: position argument \
						no is digital valide", 1);
			}
			++j;
		}
		++i;
	}
}

static void				get_info_resolution(size_t *w, size_t *h, char *str)
{
	char	**tmp;

	if (!str)
		ft_putstr_err("ERROR: .ort get info resolution == NULL", 1);
	tmp = ft_strsplit(str, '/');
	if (ft_strlen_tab(tmp) != 2)
		ft_putstr_err("ERROR: position nbr argument != 2", 1);
	get_info_resolution_sub(tmp);
	*w = (size_t)ft_atoi(tmp[0]);
	*h = (size_t)ft_atoi(tmp[1]);
	free_tab((void **)tmp);
}

void					get_ort_camera(t_env *e, char **str, size_t *i)
{
	init_ort_camera(e);
	if (e->camera)
		ft_putstr_err("ERROR: camera is already initialized", 1);
	if (!str[*i])
		ft_putstr_err("ERROR: .ort camera == NULL", 1);
	if (!str[++*i] && ft_strcmp(str[*i], "{") == 0)
		ft_putstr_err("ERROR: camera {", 1);
	while (ft_strcmp(str[++*i], "}") != 0)
	{
		if (ft_strcmp(str[*i], "resolution") == 0)
			get_info_resolution(&e->scn.cam.w, &e->scn.cam.h, str[++*i]);
		else if (ft_strcmp(str[*i], "position") == 0)
			get_info_position(&e->scn.cam.pos, str[++*i]);
		else if (ft_strcmp(str[*i], "rotate") == 0)
			get_info_rotate(&e->scn.cam.rotate, str[++*i]);
		else
			ft_putstr_err("ERROR: camera flags Unknown", 1);
	}
	e->camera = 1;
}
