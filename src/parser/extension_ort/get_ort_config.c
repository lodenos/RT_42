/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_ort_config.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodenos <glodenos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/16 21:45:03 by glodenos          #+#    #+#             */
/*   Updated: 2016/12/13 16:27:17 by glodenos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_RT.h"

static inline void		init_ort_config(t_env *e)
{
	e->gpu = 0;
	e->thread = 1;
	e->scn.resolution = 1;
	e->scn.filter = 0;
}

void					get_ort_config(t_env *e, char **str, size_t *i)
{
	size_t j;

	init_ort_config(e);
	if (e->config)
		ft_putstr_err("ERROR: .config is already initialized", 1);
	if (!str[*i])
		ft_putstr_err("ERROR: .ort .config == NULL", 1);
	if (!str[++*i] && ft_strcmp(str[*i], "{") == 0)
		ft_putstr_err("ERROR: .config {", 1);
	while (ft_strcmp(str[++*i], "}") != 0)
	{
		if (!str[*i])
			ft_putstr_err("ERROR: .config incomplete", 1);
		if (ft_strcmp(str[*i], "GPU") == 0 || ft_strcmp(str[*i], "cpu") == 0)
		{
			if (ft_strcmp(str[++*i], "on") == 0 || \
				ft_strcmp(str[*i], "ON") == 0)
				e->gpu = 1;
			else if (ft_strcmp(str[*i], "off") == 0 || \
				ft_strcmp(str[*i], "OFF") == 0)
				e->gpu = 0;
			else
				ft_putstr_err("ERROR: .config flags GPU", 1);
		}
		else if (ft_strcmp(str[*i], "thread") == 0)
		{
			if (!str[++*i])
				ft_putstr_err("ERROR: .config flags thread", 1);
			j = 0;
			while (str[*i][j])
			{
				if (str[*i][j] < '0' || str[*i][j] > '9')
					ft_putstr_err("ERROR: .config flags thread \
						value is not digital", 1);
				++j;
			}
			if ((e->thread = (size_t)ft_atoi(str[*i])) < 1)
				ft_putstr_err("ERROR: .config flags thread value is < 1", 1);
		}
		else if (ft_strcmp(str[*i], "host") == 0)
			ft_putstr_err(".config host not attributed", 1);
		else if (ft_strcmp(str[*i], "supersampling") == 0)
		{
			if (!str[++*i])
				ft_putstr_err("ERROR: .config flags supersampling", 1);
			j = 0;
			while (str[*i][j])
			{
				if (str[*i][j] < '0' || str[*i][j] > '9')
					ft_putstr_err("ERROR: .config flags \
						supersampling value is not digital", 1);
				++j;
			}
			if ((e->scn.resolution = (size_t)ft_atoi(str[*i])) < 1)
				ft_putstr_err("ERROR: .config flags \
					supersampling value is < 1", 1);
		}
		else if (ft_strcmp(str[*i], "filtered_rgb") == 0)
		{
			++*i;
			e->scn.filter = FILTERED_RGB;
			get_info_color(&e->scn.color, str[++*i]);
		}
		else if (ft_strcmp(str[*i], "filtered_sepia") == 0)
			e->scn.filter = FILTERED_SEPIA;
		else if (ft_strcmp(str[*i], "stereoscopie") == 0)
			e->scn.filter = STEREOSCOPIE;
		else if (ft_strcmp(str[*i], "filtered_black_white") == 0)
			e->scn.filter = FILTERED_BLACK_WHITE;
		else
			ft_putstr_err("ERROR: .config flags Unknown", 1);
	}
	e->config = 1;
}
