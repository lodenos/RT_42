/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_ort_config_sub.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cducaffy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 13:33:55 by cducaffy          #+#    #+#             */
/*   Updated: 2016/12/15 13:28:23 by opettex-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_rt.h"

void					get_ort_config_sub(t_env *e, char **str, size_t *i)
{
	if (ft_strcmp(str[*i], "filtered_rgb") == 0)
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
