/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   limit.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodenos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/28 01:09:13 by glodenos          #+#    #+#             */
/*   Updated: 2016/12/12 13:03:16 by opettex-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_RT.h"

inline unsigned int	limit(register float x)
{
	if (x > 255)
		return (0xFF);
	else if (x < 0)
		return (0x0);
	return ((unsigned int)x);
}
