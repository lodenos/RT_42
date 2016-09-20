/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_keyboard.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodenos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/17 06:31:37 by glodenos          #+#    #+#             */
/*   Updated: 2016/09/08 12:42:08 by anespoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void	light_intensity(t_env *e, int r, int g, int b)
{
	e->scn.spt[0].rgb.blue = e->scn.spt[0].rgb.blue + b;
	e->scn.spt[0].rgb.green = e->scn.spt[0].rgb.green + g;
	e->scn.spt[0].rgb.red = e->scn.spt[0].rgb.red + r;
	play_scene(e);
}

int		event_key_press(int k, t_env *e)
{
	(void)e;
	if (k == 53)
		exit(0);
	else if (k == 69)
		light_intensity(e, 5, 5, 5);
	else if (k == 78)
		light_intensity(e, -5, -5, -5);
	return (0);
}

int		event_key_release(int k, t_env *e)
{
	(void)e;
	(void)k;
	return (0);
}
