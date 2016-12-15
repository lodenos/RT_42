/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quadratic_equation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anespoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 15:03:47 by anespoul          #+#    #+#             */
/*   Updated: 2016/12/15 13:35:18 by opettex-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_rt.h"

struct s_roots		solve_quadratic_equation(register double a, \
		register double b, register double c)
{
	register t_roots	r;
	register double		det;

	det = b * b - 4 * a * c;
	r.x1 = (-b + sqrt(det)) / (2 * a);
	r.x2 = (-b - sqrt(det)) / (2 * a);
	return (r);
}
