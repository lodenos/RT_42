/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mouse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodenos <glodenos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/14 13:35:07 by glodenos          #+#    #+#             */
/*   Updated: 2016/10/14 14:04:45 by glodenos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_RT.h"

void    init_mouse(t_mouse *mouse)
{
    mouse->left = 0;
    mouse->right = 0;
    mouse->x = 0;
    mouse->y = 0;
    mouse->id = -1;
}
