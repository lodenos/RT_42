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
	gettimeofday(&tmp, NULL);

	v = (tmp.tv_sec * 1000000 + tmp.tv_usec) -
        (fps.tv_sec * 1000000 + fps.tv_usec);
	txt = ft_itoa(1000000 / abs(v));
    ft_putstr("FPS = ");
    ft_putendl(txt);
	free(txt);
	gettimeofday(&fps, NULL);
}
