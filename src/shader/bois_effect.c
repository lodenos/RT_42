/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perlin_noise2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opettex- <opettex-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 23:45:57 by opettex-          #+#    #+#             */
/*   Updated: 2016/11/04 23:45:58 by opettex-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_RT.h"

Uint32	get_color(double r, double g, double b)
{
	return ((((int)(r * 255)) << 24) + (((int)(g * 255)) << 16) + ((int)(b * 255) << 8) + 0xFF);
}

void	bois_noise(t_obj *obj, t_noise *n, unsigned int *img)
{
	double	value;
	int		resultat;			

	n->c1 = 0x856D4D;
	n->c2 = 0x4E3D28;
	n->seuil = 0.2;
	value = fmod(coherent_noise(x, y, PERSISTENCE), n->seuil);
	if (value > n->seuil / 2)
		valeur = n->seuil - value;


}
