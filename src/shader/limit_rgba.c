/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   limit_rgba.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodenos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/23 06:01:31 by glodenos          #+#    #+#             */
/*   Updated: 2016/09/23 06:38:58 by glodenos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_RT.h"

inline t_rgba   limit_rgba(register t_rgba a, register t_rgba b)
{
    register size_t max;
    register t_rgba color;

    max = (size_t)(a.red + b.red);
    color.red = (max > 255) ? 0xFF : (unsigned char)max;
    max = (size_t)(a.green + b.green);
    color.green = (max > 255) ? 0xFF : (unsigned char)max;
    max = (size_t)(a.blue + b.blue);
    color.blue = (max > 255) ? 0xFF : (unsigned char)max;
    max = (size_t)(a.alpha + b.alpha);
    color.alpha = (max > 255) ? 0xFF : (unsigned char)max;
    return (color);
}
