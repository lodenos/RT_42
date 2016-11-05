/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perlin_noise.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opettex- <opettex-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 02:11:22 by opettex-          #+#    #+#             */
/*   Updated: 2016/11/05 02:11:23 by opettex-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_RT.h"

void	init_bruit(int t, int p, int n)
{
	int i;
	int nb_octaves;
	int len;
	int pas;
	double	value;

	pas = 0;
	nb_octaves = n;
	len = 0;
	i = 0;
	if (len != 0)
		free(value);
	len = t;
	pas = p;
	value = (double *)malloc(sizeof(double) (int)ceil(len * pow(2, nb_octaves - 1) / pas));
	srand(time(NULL));
	while (i < ceil(taille *  pow(2, nombre_octaves  - 1)  / pas))
	{
		value[i] = (double)rand() / RAND_MAX;
		++i;
	}
}

void	destroy()
{
	if (len != 0)
		free(value);
	len = 0;
}

double	bruit(int t)
{
	t = (t<<13) ^ t;
	t = (t * (t * t * 15731 + 789221) + 1376312589);
	return (1.0 - (t & 0x7fffffff) / 1073741824.0);
}

double	interpolation_lineaire(double a, double b, double x)
{
	return (a * (1 - x) + b * x);
}

double	interpolation_cos(double a, double b, double x)
{
	double k;

	k = (1 - cos(x * PI)) / 2;
	return (interpolation_cos(a, b, k)); 
}

double fonction_bruit(double x)
{
	int i;
	int pas;

	pas = 0;
	i = (int)(x / pas);

	return (interpolation_cos(bruit(i), bruit(i + 1), (x / pas) % 1));
}

double	bruit_coherent(double x, double persistance, int nb_octaves)
{
	double	somme;
	double	p;
	int 	f;
	int 	i;

	somme = 0;
	p = 1;
	f = 1;
	i = 0;
	while (i < nb_octaves)
	{
		somme += p * fonction_bruit(x * f);
		p *= persistance;
		f *= 2;
		++i;
	}
	return (somme * (1 - persistance) / (1 - p));
}