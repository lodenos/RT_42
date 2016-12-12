/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_info_rotate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodenos <glodenos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/01 19:07:15 by glodenos          #+#    #+#             */
/*   Updated: 2016/12/09 13:51:04 by glodenos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_RT.h"

void		get_info_rotate(cl_float3 *rotate, char *str)
{
	size_t	i;
	size_t	j;
	size_t	k;
	char	**tmp;

	i = 0;
	if (!str)
		ft_putstr_err("ERROR: .ort get info rotate == NULL", 1);
	tmp = ft_strsplit(str, '/');
	if (ft_strlen_tab(tmp) != 3)
		ft_putstr_err("ERROR: ", 1);
	while (tmp[i])
	{
		j = 0;
		if (ft_strlen(tmp[i]) > 16)
			while (tmp[i][j])
			{
				if (tmp[i][j] < '0' || tmp[i][j] > '9')
				{
					if (tmp[i][j] == '.' && !k)
						k = 1;
					else if (tmp[i][j] != '-')
						ft_putstr_err("ERROR: ", 1);
				}
				++j;
			}
		++i;
	}
	rotate->x = (float)atof(tmp[0]) * D_TO_RAD;
	rotate->y = (float)atof(tmp[1]) * D_TO_RAD;
	rotate->z = (float)atof(tmp[2]) * D_TO_RAD;
	*rotate = normalize(*rotate);
	free_tab((void **)tmp);
}
