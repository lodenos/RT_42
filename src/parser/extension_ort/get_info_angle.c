/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_info_angle.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodenos <glodenos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/01 14:58:16 by glodenos          #+#    #+#             */
/*   Updated: 2016/12/15 13:26:29 by opettex-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_rt.h"

void		get_info_angle(t_env *e, char **str, size_t *i)
{
	size_t	j;

	j = 0;
	if (!str[++*i])
		ft_putstr_err("ERROR: .ort angle -> NULL", 1);
	while (str[*i][j])
	{
		if (str[*i][j] < '0' || str[*i][j] > '9')
			ft_putstr_err("ERROR: angle value is not digital", 1);
		++j;
	}
	e->obj[e->elem_obj].angle = ft_atoi(str[*i]) * D_TO_RAD;
}
