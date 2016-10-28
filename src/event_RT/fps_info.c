/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fps_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodenos <glodenos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/17 16:50:38 by glodenos          #+#    #+#             */
/*   Updated: 2016/10/17 20:30:40 by glodenos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_RT.h"

inline void fps_info(void)
{
    static struct timeval   fps;
	struct timeval			tmp;
	char					*txt;
	int						v;

	txt = NULL;
    if (gettimeofday(&tmp, NULL) == -1)
        ft_putstr_err("ERROR: Crash gettimeofday", 1);
	v = (int)(tmp.tv_sec * 1000000 + tmp.tv_usec) - (int)(fps.tv_sec * 1000000 + fps.tv_usec);
	txt = ft_itoa(1000000 / abs(v));
    ft_putstr("\e[1AFPS = ");
    ft_putendl(txt);
	free(txt);
    if (gettimeofday(&fps, NULL) == -1)
        ft_putstr_err("ERROR: Crash gettimeofday", 1);
}
