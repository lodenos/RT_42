/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_keyboard.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodenos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/29 16:38:34 by glodenos          #+#    #+#             */
/*   Updated: 2016/09/29 16:50:57 by glodenos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_RT.h"

void    init_keyboard(t_key *key)
{
    key->key_a = 0;
    key->key_comma = 0;
    key->key_d = 0;
    key->key_down = 0;
    key->key_left = 0;
    key->key_lshift = 0;
    key->key_point = 0;
    key->key_right = 0;
    key->key_s = 0;
    key->key_space = 0;
    key->key_up = 0;
    key->key_w = 0;
}
