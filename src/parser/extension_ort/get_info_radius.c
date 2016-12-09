/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_info_radius.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodenos <glodenos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/01 22:00:45 by glodenos          #+#    #+#             */
/*   Updated: 2016/12/09 13:49:57 by glodenos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_RT.h"

void    get_info_radius(cl_float3 *radius, char *str)
{
	size_t	i;
	size_t	j;
	_Bool	k;
	char	**tmp;

	i = 0;
	k = 0;
	if (!str)
		ft_putstr_err("ERROR: .ort == NULL", 1);
	tmp = ft_strsplit(str, '/');
	if (ft_strlen_tab(tmp) != 3)
		ft_putstr_err("ERROR: radius nbr argument != 3", 1);
	while (tmp[i])
	{
		j = 0;
		if (ft_strlen(tmp[i]) > 16)
			ft_putstr_err("ERROR: the length of the number is too large", 1);
		while (tmp[i][j])
		{
			if (tmp[i][j] < '0' || tmp[i][j] > '9')
			{
				if (tmp[i][j] == '.' && !k)
					k = 1;
				else if (tmp[i][j] != '-')
					ft_putstr_err("ERROR: position argument no is digital valide", 1);
			}
			++j;
		}
		++i;
	}
	radius->x = (float)atof(tmp[0]);
	radius->y = (float)atof(tmp[1]);
	radius->z = (float)atof(tmp[2]);
	free_tab((void **)tmp);
}
