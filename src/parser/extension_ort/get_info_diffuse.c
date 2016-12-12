/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_info_diffuse.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodenos <glodenos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/01 17:31:41 by glodenos          #+#    #+#             */
/*   Updated: 2016/12/09 13:48:32 by glodenos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_RT.h"

void		get_info_diffuse(float *diffuse, char *str)
{
	size_t	i;
	int		k;

	i = 0;
	k = 0;
	if (!str)
		ft_putstr_err("ERROR: .ort == NULL", 1);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
		{
			if (str[i] == '.' && !k)
				k = 1;
			else
				ft_putstr_err("ERROR: ", 1);
		}
		++i;
	}
	*diffuse = (float)atof(str);
	if ((int)*diffuse > 100)
		ft_putstr_err("ERROR: ", 1);
	*diffuse *= 0.01f;
}
