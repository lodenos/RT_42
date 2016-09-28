/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   limit_rgba.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodenos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/28 01:09:13 by glodenos          #+#    #+#             */
/*   Updated: 2016/09/28 01:48:34 by glodenos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_RT.h"

inline unsigned char    limit_rgba(register double x)
{
	printf("x = %lf", x);
    if (x > 255)
        return (255);
    else if (x < 0)
        return (0);
    return ((unsigned char)x);
}
