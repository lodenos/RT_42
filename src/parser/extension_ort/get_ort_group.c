/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_ort_group.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodenos <glodenos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/16 21:59:21 by glodenos          #+#    #+#             */
/*   Updated: 2016/12/15 13:28:34 by opettex-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_rt.h"

void		get_ort_group(t_env *e, char **str, size_t *i)
{
	e->group = 1;
	if (!str[++*i])
		ft_putstr_err("ERROR: Group -> NULL ?", 1);
	if (str[*i][0] != '{')
		ft_putstr_err("ERROR: Group { ?", 1);
	while (str[++*i][0] != '}')
	{
		if (!str[*i])
			ft_putstr_err("ERROR: Group -> NULL ?", 1);
		get_info_ort(e, str, i);
	}
}
